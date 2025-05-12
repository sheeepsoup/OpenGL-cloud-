#version 330 core
#define MAX_DIST 200
#define MAX_STEP 100
#define MIN_DIST 0.01
out vec4 FragColor;
uniform vec3 cameraPos;
uniform vec3 Up;
uniform vec3 Right;
uniform vec3 Forward;


//				  x y z r
vec4 QiuPos = vec4(0,1,6,1);



//获取距离			当前点的坐标
float GetDist(vec3 nowPoint){
	float k = length(nowPoint - QiuPos.xyz) - QiuPos.w;

	//y
	float y = nowPoint.y;

	return min(k,y);

}


//rayMArching	初始点坐标
float RayMarching(vec3 p){
	vec3 dir = normalize(p);
	//当前点的坐标
	vec3 nowPointa = cameraPos;

	for(int i = 0;i<MAX_STEP;i++){
		float Dist = GetDist(nowPointa);  

	
		if(Dist < MIN_DIST)break;
		
		if( length(nowPointa - cameraPos) >= MAX_DIST)break;
		nowPointa += dir * Dist;



	}

	return length(nowPointa - cameraPos);

}



void main(){
	vec2 falt = vec2(800,600);
	vec2 uv = (gl_FragCoord.xy - falt.xy * 0.5) / falt.y;
	vec3 uvW = vec3(Forward + Right * uv.x - Up * uv.y);

	//vec3 p = vec3(uv,1);
	float distan = RayMarching(uvW);
	distan /= 6;
	FragColor = vec4(distan,distan,distan,1);

}

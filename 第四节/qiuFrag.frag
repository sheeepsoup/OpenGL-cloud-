#version 330 core
#define MAX_DIST 500
#define MAX_STEP 200
#define MIN_DIST 0.01
#define STEP_LENT 0.2

out vec4 FragColor;
uniform vec3 cameraPos;
uniform vec3 Up;
uniform vec3 Right;
uniform vec3 Forward;
uniform sampler3D noise;

//				  x y z r
vec3 CubePos = vec3(0,50,6);
vec3 CubeSize = vec3(200,2,200);


//获取距离			当前点的坐标
float GetDist(vec3 nowPoint){
	float k = length( max(abs(nowPoint - CubePos) - CubeSize,0));
	//y
	float y = nowPoint.y;

	return min(k,y);

}

//获取取样坐标
vec3 GetCoord(vec3 nowpoint){
	vec3 reulst = vec3(0);
	reulst =  ( ((nowpoint - CubePos) / CubeSize) + 1 ) / 2;//纹理取样坐标
	return reulst;

}


//rayMArching	初始点坐标
float RayMarching(vec3 p){
	vec3 dir = normalize(p);
	//当前点的坐标
	vec3 nowPointa = cameraPos;
	//最终步数
		int StepNum = 0;
		//最终密度
		float Density = 0;
	for(int i = 0;i<MAX_STEP;i++){
		float Dist = GetDist(nowPointa);  

		
		if(Dist < MIN_DIST){
			//说明成功进入内部
			//接下来固定步长步进
			nowPointa += dir * STEP_LENT;
			float Dist2 = GetDist(nowPointa);  
			if(Dist2!= 0){
				//说明出去了
				break;
			}
			else{//进入内部
				//取样纹理
				vec4 NoiseColor = texture(noise,GetCoord(nowPointa));
				Density += NoiseColor.r;


				StepNum++;
			}
		};
		
		if( length(nowPointa - cameraPos) >= MAX_DIST)break;
		nowPointa += dir * Dist;



	}

	return Density;

}



void main(){
	vec2 falt = vec2(800,600);
	vec2 uv = (gl_FragCoord.xy - falt.xy * 0.5) / falt.y;
	vec3 uvW = vec3(Forward + Right * uv.x - Up * uv.y);

	//vec3 p = vec3(uv,1);
	float dense = RayMarching(uvW);
	float w = smoothstep(0,10,dense);
	vec3 baseColor = vec3(1);
	vec3 finalColor = baseColor *	w; 

	//若密度过大,提供蓝色色调
	vec3 bulueColor = 1 - vec3(0.2509,0.4627,0.9098);


	FragColor = vec4(finalColor - bulueColor * (1-dense),w);

}

#version 120

varying vec3 coordonnee_3d;

//Un Fragment Shader minimaliste
void main (void)
{
    float x = abs(coordonnee_3d.x);
    float y = abs(coordonnee_3d.y);
    float z = abs(coordonnee_3d.z);


    gl_FragColor = vec4(x,y,z,1.0);
}

#version 120

varying vec4 pos;

//Un Vertex Shader minimaliste
void main (void)
{
    //Projection du sommet
    gl_Position = gl_Vertex;
    pos=gl_Vertex;
}

#version 120

uniform vec4 translation;
uniform mat4 rotation;


//Un Vertex Shader minimaliste
void main (void)
{
    //Coordonnees du sommet
    vec4 p = rotation*gl_Vertex+translation;

    //position dans l'espace ecran
    gl_Position = p;
}

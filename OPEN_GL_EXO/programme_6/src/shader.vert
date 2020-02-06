#version 120

uniform vec4 translation;
uniform mat4 rotation;
uniform mat4 projection;

varying vec3 coordonnee_3d;

//Un Vertex Shader minimaliste
void main (void)
{
    //Les coordonnees 3D du sommet
    coordonnee_3d = gl_Vertex.xyz;

    //Coordonnees du sommet
    vec4 p = rotation*gl_Vertex+translation;

    //Projection du sommet
    p = projection*p;

    //position dans l'espace ecran
    gl_Position = p;
}

#version 120

varying vec4 pos;

//Un Fragment Shader minimaliste
void main (void)
{
    //couleur du fragment
    gl_FragColor = pos;
}

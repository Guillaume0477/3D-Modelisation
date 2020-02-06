#version 120

//Un Fragment Shader minimaliste
void main (void)
{
    float r=abs(gl_FragCoord.x/600.0);
    float g=abs(gl_FragCoord.y/600.0);

    //couleur du fragment
    gl_FragColor = vec4(r,g,1.0,1.0);
}

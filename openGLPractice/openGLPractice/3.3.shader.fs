#version 330 core

in vec3 ourColor;

out vec4 FragColor;

// since position coordinate that are less than 0.0f (-0.5f from example)
// will be set to 0.0f, the bottom left point (-0.5f, -0.5f, 0.0f) will
// be set to (0.0f, 0.0f, 0.0f) in ourColor, which means FragColor will
// be (0.0f, 0.0f, 0.0f, 1.0f), known as pure black.
void main() {
    FragColor = vec4(ourColor, 1.0);
}

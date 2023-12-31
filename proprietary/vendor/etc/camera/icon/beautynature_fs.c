#version 300 es

precision highp float;
uniform sampler2D sTexture;
in vec2 vTexCoor;
out vec4 uFragColor;

void main() {

    vec4 color = texture(sTexture, vTexCoor);

    color.r = 1.0 * color.r - 0.2 * color.r * (color.r - 1.0);
    color.g = 1.0 * color.g - 0.2 * color.g * (color.g - 1.0);
    color.b = 1.0 * color.b - 0.2 * color.b * (color.b - 1.0);

    color.rgb = min(color.rgb, 1.0);
    color.rgb = max(color.rgb, 0.0);

    color.r = 1.0 * color.r + (0.15) * (1.0 - color.r);
    color.g = 0.95 * color.g + (0.10) * (1.0 - color.g);
    color.b = 1.0 * color.b + (0.15) * (1.0 - color.b);
    uFragColor = vec4(color.rgb, color.a);
}

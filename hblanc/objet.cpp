const Uint8 *state = SDL_GetKeyboardState(NULL);
if (state[SDL_SCANCODE_RETURN]) {
    printf("<RETURN> is pressed.\n");
}
if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_UP]) {
    printf("Right and Up Keys Pressed.\n");
}
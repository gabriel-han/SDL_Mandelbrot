#include <SDL2/SDL.h>
#include <numeric>
#include <complex>

const int SCALE = 1;

int is_in_set(std::complex<double> c)
{
    std::complex<double> z(0, 0);
    for (int i = 0; i < 250; i++)
    {
        z = std::pow(z, 2) + c;
        if (std::norm(z) > 10)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(1000 * SCALE, 1000 * SCALE, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, SCALE, SCALE);
    
    for (double x = 0.0; x < 1.0; x += 0.001)
    {
        for (double y = 0.0; y < 1.0; y += 0.001)
        {
            double point_x = std::lerp(-2.0, 2.0, x);
            double point_y = std::lerp(-2.0, 2.0, y);
            int iters = is_in_set(std::complex<double>(point_x, point_y));
            if (iters == 0)
            {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawPointF(
                                     renderer,
                                     static_cast<float>(x * 1000.0),
                                     static_cast<float>(y * 1000.0));
            }
            else
            {
                SDL_SetRenderDrawColor(
                                       renderer,
                                       static_cast<Uint8>(10 * iters % 255),
                                       static_cast<Uint8>(10 * iters % 255),
                                       static_cast<Uint8>(10 * iters % 255),
                                       255);
                SDL_RenderDrawPointF(
                                     renderer,
                                     static_cast<float>(x * 1000.0),
                                     static_cast<float>(y * 1000.0));
            }
        }
    }
    
    SDL_RenderPresent(renderer);
    
    SDL_Event e;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            if (e.type == SDL_KEYDOWN)
            {
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                quit = true;
            }
        }
    }
}

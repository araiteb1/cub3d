#include <mlx.h>

int main(void) {
    void *mlx;
    void *win;
    void *img;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "My MinilibX Window");
    img = mlx_new_image(mlx, 55, 45);
    mlx_loop(mlx);

    return (0);
}
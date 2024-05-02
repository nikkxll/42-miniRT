/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:33:31 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/02 14:28:20 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/vec3.h"
#include "../includes/MLX42.h"

typedef struct s_minirt
{
	mlx_t		*mlx;
	mlx_image_t	*image;
    t_viewport  screen;
}	t_minirt;

/*
int main()
{
    ft_printf("Hello world!\n");
    return (0);
}
*/

/*
void	print_picture(t_minirt *rt)
{
    int i;
    int j;

    i = -1;
    while (++i < rt->)
	{
		i = -1;
		while (++i < fdf->size_x - 1)
		{
			mlx_put_pixel(fdf->image, r0.x, r0.y, color);
		}
	}
	i = -1;
}
*/

void	ft_hook_image(void *data)
{
	t_minirt	*rt;

	rt = data;
	ft_memset(rt->image->pixels, CHANNELBACK,
		rt->image->width * rt->image->height * sizeof(int32_t));
	//print_picture(rt);
}



int32_t	main(int32_t argc, char *argv[])
{
    t_minirt rt;

	t_num foc = 90;
	int	n_x = 3;
	int n_y = 3;
	rt.screen = (t_viewport){foc, n_x, n_y, n_x * n_y, NULL};

    (void)argv;
    (void)argc;

	rt.mlx = mlx_init(MLXWIDTH, MLXHEIGHT, "MLX42", true);
	if (!rt.mlx)
        return (1); //		ft_mlx_error(fdf, 0);
	rt.image = mlx_new_image(rt.mlx, IMAGE_WIDTH, IMAGE_HEIGHT);
	if (!rt.image)
	    return (1); //	ft_mlx_error(fdf, 1);
	if (mlx_image_to_window(rt.mlx, rt.image, 0, 0) == -1)
		return (1); //ft_mlx_error(fdf, 1);
	mlx_loop_hook(rt.mlx, ft_hook_image, &rt);
	mlx_loop(rt.mlx);
	mlx_terminate(rt.mlx);
	return (EXIT_SUCCESS);
}
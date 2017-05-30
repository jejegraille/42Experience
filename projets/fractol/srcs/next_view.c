/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 10:30:58 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/28 12:42:31 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractole.h>
#include <libft.h>

static void		nextv_mandel(t_graph *gr)
{
	int		max;

	max = 5;
	gr->view > max && (gr->view = 0);
	if (gr->view == 0)
		change_view(gr, get_point(-0.56195, 0.64362, 0),
			0.00003, 0.00003);
	if (gr->view == 1)
		change_view(gr, get_point(-0.59253, 0.62060, 0),
			0.00001, 0.00001);
	if (gr->view == 2)
		change_view(gr, get_point(-0.79579189, -0.17181885, 0),
			0.00000138, 0.00000117);
	if (gr->view == 3)
		change_view(gr, get_point(-0.37325771, -0.65425171, 0),
			0.00013133, 0.00011187);
	if (gr->view == 4)
		change_view(gr, get_point(-1.25751667, 0.07367708, 0),
			0.00000636, 0.00000542);
	if (gr->view == 5)
		change_view(gr, get_point(-0.75, -0.05, 0), 0.0045, 0.00383);
	gr->view += 1;
}

static void		nextv_ship(t_graph *gr)
{
	int		max;

	max = 6;
	gr->view > max && (gr->view = 0);
	if (gr->view == 0)
		change_view(gr, get_point(-1.74729997, -0.03814247, 0),
				0.00022463, 0.00021102);
	if (gr->view == 1)
		change_view(gr, get_point(-1.86037499, -0.00875923, 0),
				0.00000100, 0.00000094);
	if (gr->view == 2)
		change_view(gr, get_point(-0.70849051, -1.09808030, 0),
				0.00001955, 0.00001836);
	if (gr->view == 3)
		change_view(gr, get_point(0.7680212121, -1.2780131319, 0),
				0.00000000028, 0.00000000028);
	if (gr->view == 4)
		change_view(gr, get_point(-1.6564217772, -0.0124958052, 0),
				0.0000000029, 0.0000000027);
	if (gr->view == 5)
		change_view(gr, get_point(-1.5883261083, -0.0056810848, 0),
				0.0000471969, 0.0000443365);
	if (gr->view == 6)
		change_view(gr, get_point(-0.35, -0.45, 0), 0.0055, 0.00516);
	gr->view += 1;
}

static void		nextv_bird(t_graph *gr)
{
	int		max;

	max = 5;
	gr->view > max && (gr->view = 0);
	if (gr->view == 0)
		change_view(gr, get_point(-0.7854502237, -0.9242231711, 0),
				0.0000138393, 0.0000115327);
	if (gr->view == 1)
		change_view(gr, get_point(0.1712492332, -0.6171658814, 0),
				0.0000041811, 0.0000034842);
	if (gr->view == 2)
		change_view(gr, get_point(-0.2597723895, -0.7884685960, 0),
				0.0000018681, 0.0000015567);
	if (gr->view == 3)
		change_view(gr, get_point(-0.2600922032, -0.7890581506, 0),
				0.0000001783, 0.0000001486);
	if (gr->view == 3)
		change_view(gr, get_point(0.0284542555, -0.9028943249, 0),
				0.0000035309, 0.0000029427);
	if (gr->view == 4)
		change_view(gr, get_point(-1.3899066217, -0.0334789844, 0),
				0.0000082466, 0.0000068722);
	if (gr->view == 5)
		change_view(gr, get_point(-0.4, 0, 0), 0.006, 0.005);
	gr->view += 1;
}

static void		nextv_rock(t_graph *gr)
{
	int		max;

	max = 4;
	gr->view > max && (gr->view = 0);
	if (gr->view == 0)
		change_view(gr, get_point(0.9999372575, -1.2057899555, 0),
				0.0000079115, 0.0000056800);
	if (gr->view == 1)
		change_view(gr, get_point(1.2418002482, 1.0736549515, 0),
				0.0000732696, 0.0000526038);
	if (gr->view == 2)
		change_view(gr, get_point(0.4017286572, 1.2590304338, 0),
				0.0000056446, 0.0000040525);
	if (gr->view == 3)
		change_view(gr, get_point(1.8227552062, -0.5003366765, 0),
				0.0001219764, 0.0000875720);
	if (gr->view == 4)
		change_view(gr, get_point(-1.1, -0.2, 0), 0.013, 0.0093);
	gr->view += 1;
}

void			nextview(t_graph *gr)
{
	if (gr->fct_nbr == 0)
		nextv_mandel(gr);
	if (gr->fct_nbr == 2)
		nextv_ship(gr);
	if (gr->fct_nbr == 3)
		nextv_bird(gr);
	if (gr->fct_nbr == 4)
		nextv_rock(gr);
}

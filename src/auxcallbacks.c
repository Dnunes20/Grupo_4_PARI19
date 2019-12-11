/** *     @file   auxcallbacks.c
 *     @brief  Auxiliary functions that are not callbacks but are used by them
 *
 *     Detailed description starts here.
 *
 *     @author  Vitor Santos, vitor@ua.pt
 *
 * =========================================================
 */

#define _AUXCALLBACKS_C_

#include "myf.h"


//--- Functions associated to the main callbacks for the drawing area ---//
//--- Students have to develop them in a team work ---//
// One of them is given as example : pari_draw_regularpolygon()

/**
 * @brief Draw a regular polygon
 * 
 * @param event 
 */
void pari_draw_regularpolygon(GdkEvent *event)
{
	static int last_button=0;
	GdkEventButton *geb=(GdkEventButton *)event; //aux variable
	switch( event->type)
	{
		case GDK_BUTTON_PRESS: //it's a new one
			last_button=geb->button;
			if( geb->button == 1 )  //left button
			{
				double x=geb->x;
				double y=geb->y;
				p_polygon *npoly=(p_polygon *)malloc(sizeof(p_polygon));
				npoly->x=(double*)malloc((statusG.regularpolygon_vertices)*sizeof(double));
				npoly->y=(double*)malloc((statusG.regularpolygon_vertices)*sizeof(double));
				double ang=2*M_PI/statusG.regularpolygon_vertices;
				double radius=20;
				for(int n=0; n< statusG.regularpolygon_vertices;n++)
				{
					double x1=x+radius*cos( n*ang );
					double y1=y+radius*sin( n*ang );
					npoly->x[n]=x1;
					npoly->y[n]=y1;
				}
				npoly->num_points=statusG.regularpolygon_vertices;  //to close the polygon
				npoly->x0=x;
				npoly->y0=y;
				npoly->line_color=0;
				npoly->fill_color=statusG.regularpolygon_rgbcolor;

				pari_add_poly_to_main_drawing(npoly, pdG);
			}

			break;

		case GDK_MOTION_NOTIFY:  //mouse motion means modifying one just drawn
			if( last_button == 1 )  //if last pressed button was the right one (avoid motion from other buttons)
			{
				double x=geb->x;
				double y=geb->y;
				double x0=pdG->polys[pdG->num_poly-1]->x0;
				double y0=pdG->polys[pdG->num_poly-1]->y0;
				p_polygon *npoly=pdG->polys[pdG->num_poly-1];
				double ang=2*M_PI/statusG.regularpolygon_vertices;
				double radius=sqrt((x-x0)*(x-x0)+(y-y0)*(y-y0));
				double angoff=atan2( y-y0, x-x0);
				for(int n=0; n < statusG.regularpolygon_vertices;n++)
				{
					double x1=x0+radius*cos( n*ang+angoff );
					double y1=y0+radius*sin( n*ang+angoff );
					npoly->x[n]=x1;
					npoly->y[n]=y1;
				}
			}

			break;

		default:
			//Does nothing
			break;
	}	

}

/**
 * @brief Draw a star polygon
 * 
 * @param event 
 */
void pari_draw_starpolygon(GdkEvent *event)
{
	static int last_button=0;
	GdkEventButton *geb=(GdkEventButton *)event; //aux variable
	switch( event->type)
	{
		case GDK_BUTTON_PRESS: //it's a new one
			last_button=geb->button;
			if( geb->button == 1 )  //left button
			{
				double x=geb->x; 
				double y=geb->y;
				p_polygon *npoly=(p_polygon *)malloc(sizeof(p_polygon));
				npoly->x=(double*)malloc((2*statusG.starpolygon_vertices)*sizeof(double));
				npoly->y=(double*)malloc((2*statusG.starpolygon_vertices)*sizeof(double));
				double ang=2*M_PI/statusG.starpolygon_vertices;
				double radius=20;
				double radius_m=10;

				for(int n=0; n< 2*statusG.starpolygon_vertices;n++)
				{   
					if (n%2==0)
					{
						double x1=x+radius*cos( n*ang );
						double y1=y+radius*sin( n*ang );
						npoly->x[n]=x1;
						npoly->y[n]=y1;
					}
					else
					{
						double x1=x+radius_m*cos( n*ang );
						double y1=y+radius_m*sin( n*ang );
						npoly->x[n]=x1;
						npoly->y[n]=y1;
					}
					
					
					
				}
				npoly->num_points=2*statusG.starpolygon_vertices;  //to close the polygon
				npoly->x0=x;
				npoly->y0=y;
				npoly->line_color=0;
				npoly->fill_color=2*statusG.starpolygon_rgbcolor;

				pari_add_poly_to_main_drawing(npoly, pdG);
			}

			break;

		case GDK_MOTION_NOTIFY:  //mouse motion means modifying one just drawn
			if( last_button == 1 )  //if last pressed button was the right one (avoid motion from other buttons)
			{
				double x=geb->x;
				double y=geb->y;
				double x0=pdG->polys[pdG->num_poly-1]->x0;
				double y0=pdG->polys[pdG->num_poly-1]->y0;
				p_polygon *npoly=pdG->polys[pdG->num_poly-1];
				double ang=2*M_PI/statusG.starpolygon_vertices;
				double radius=sqrt((x-x0)*(x-x0)+(y-y0)*(y-y0));
				double radius_m=radius/2;
				double angoff=atan2( y-y0, x-x0);
				for(int n=0; n < 2*statusG.starpolygon_vertices;n++)
				{
					if (n%2==0)
					{
						double x1=x+radius*cos( n*ang );
						double y1=y+radius*sin( n*ang );
						npoly->x[n]=x1;
						npoly->y[n]=y1;
					}
					else
					{
						double x1=x+radius_m*cos( n*ang);
						double y1=y+radius_m*sin( n*ang );
						npoly->x[n]=x1;
						npoly->y[n]=y1;
					}
				}
			}

			break;

		default:
			//Does nothing
			break;
	}	
}

/**
 * @brief Draw a free hand polygon
 * 
 * @param event 
 */
void pari_draw_freehandpolygon(GdkEvent *event)
{
	static int last_button=0;
	GdkEventButton *geb=(GdkEventButton *)event; //aux variable
	switch( event->type)
	{
		case GDK_BUTTON_PRESS: //it's a new one
			last_button=geb->button;
			if( geb->button == 1 )  //left button
			{
				double x=geb->x;
				double y=geb->y;
				p_polygon *npoly=(p_polygon *)malloc(sizeof(p_polygon));
				npoly->x=(double*)malloc((statusG.freehandpolygon_vertices)*sizeof(double));
				npoly->y=(double*)malloc((statusG.freehandpolygon_vertices)*sizeof(double));
				for(int n=0; n< statusG.freehandpolygon_vertices;n++)
				{
					srand(time(0));
					double x1=x+(rand() % (200-100+1))+100;
					double y1=y+(rand() % (200-100+1))+100;
					npoly->x[n]=x1;
					npoly->y[n]=y1;
				}
				npoly->num_points=statusG.freehandpolygon_vertices;  //to close the polygon
				npoly->x0=x;
				npoly->y0=y;
				npoly->line_color=0;
				npoly->fill_color=statusG.freehandpolygon_rgbcolor;

				pari_add_poly_to_main_drawing(npoly, pdG);
			}

			break;

		case GDK_MOTION_NOTIFY:  //mouse motion means modifying one just drawn
			if( last_button == 1 )  //if last pressed button was the right one (avoid motion from other buttons)
			{
				double x=geb->x;
				double y=geb->y;
				double x0=pdG->polys[pdG->num_poly-1]->x0;
				double y0=pdG->polys[pdG->num_poly-1]->y0;
				p_polygon *npoly=pdG->polys[pdG->num_poly-1];
				double ang=2*M_PI/statusG.freehandpolygon_vertices;
				double radius=sqrt((x-x0)*(x-x0)+(y-y0)*(y-y0));
				double angoff=atan2( y-y0, x-x0);
				for(int n=0; n < statusG.freehandpolygon_vertices;n++)
				{
					double x1=x+(rand() % (200-100+1))+100;
					double y1=y+(rand() % (200-100+1))+100;
					npoly->x[n]=x1;
					npoly->y[n]=y1;
				}
			}

			break;

		default:
			//Does nothing
			break;
	}	

}

/**
 * @brief Draw a circular crown
 * 
 * @param event 
 */
void pari_draw_circularcrown(GdkEvent *event)
{
	//...
}

/**
 * @brief Draw the strings
 * 
 * @param event 
 */
void pari_draw_text(GdkEvent *event)
{
	//...
}



#include <iostream>
#include <time.h>
#include <GL/glut.h>
#include <math.h>
#include <unistd.h>
#include "keySynchStruct.h"

#define P_1 0
#define P_1_X 0
#define P_1_Y 1

#define P_2 1
#define P_2_X 0
#define P_2_Y 1

#define _X 0
#define _Y 1

struct LineStruct{
	bool init;
	bool error;
	float points_point[2][2];
	float points_changeIn[2];
	bool  distenceSet;
	float points_distence;
	float movement_radius;
	float movement_diameter;
	float movement_circumference;
	float movement_area;
	float movement_angle;
	bool inRadians;

}line;

void enumerate_line_data(void){
	printf("point1: (%f, %f)\n", line.points_point[P_1][P_1_X], line.points_point[P_1][P_1_Y]);
	printf("point2: (%f, %f)\n", line.points_point[P_2][P_2_X], line.points_point[P_2][P_2_Y]);
	printf("change in X: %f\n", line.points_changeIn[_X]);
	printf("change in Y: %f\n", line.points_changeIn[_Y]);
	printf("distance P1 -> P2: %f\n", line.points_distence);
	printf("current angle: %f (%f)\n", line.movement_angle, line.movement_angle*(180/M_PI));
	
	/*endl*/
	printf("\n");
	//fflush(stdout);
}

void setPoints(void){
	std::cout<<"Enter point 1 x: ";
	std::cin>>line.points_point[P_1][P_1_X];
	std::cout<<"Enter point 1 y: ";
	std::cin>>line.points_point[P_1][P_1_Y];

	std::cout<<"\nEnter point 2 x: ";
	std::cin>>line.points_point[P_2][P_2_X];
	std::cout<<"Enter point 2 y: ";
	std::cin>>line.points_point[P_2][P_2_Y];

	std::cout<<std::endl;
	line.init = true;
}

/*
 * This function also sets the change in X and Y
 */
void getPointsDist(void){
	float changeIn_total;
	float xChange_power, yChange_power;
	if(line.init == false){
		printf("can't get distence because LineStruct is unitintialized\n");
		line.error = true;

	}else{
		line.points_changeIn[_X] = line.points_point[P_2][P_2_X] - line.points_point[P_1][P_1_X];
		line.points_changeIn[_Y] = line.points_point[P_2][P_2_Y] - line.points_point[P_1][P_1_Y];
			
		if(line.points_changeIn[_X] < 0){
			line.points_changeIn[_X] = line.points_changeIn[_X] * (-1);
		}
		if(line.points_changeIn[_Y] < 0){
			line.points_changeIn[_Y] = line.points_changeIn[_Y] * (-1);
		}
		xChange_power = pow(line.points_changeIn[_X], 2);
		yChange_power = pow(line.points_changeIn[_Y], 2);

		changeIn_total = xChange_power + yChange_power;
		
		if(changeIn_total < 0){
			changeIn_total = changeIn_total * (-1);
			line.points_distence = sqrt(changeIn_total);
		}else{
			line.points_distence = sqrt(changeIn_total);
		}
		
		line.distenceSet = true;
	}
}

/*
 * Gets the movement angle in radians
 */
void getCurrentAngle_R(void){
	float pointDistenceQuotent;
	float radianConverter = M_PI/180;

	float changeIn_total;
        float xChange_power, yChange_power;
	float points_imaginary[2];
	float points_imaginary_distance;

	if(line.init == false){
		printf("can't get distence because LineStruct is unitintialized\n");
                line.error = true;
           
	}else{
		if(line.distenceSet == false){
			printf("\tsetting dist\n");
			getPointsDist();
		}

		if((line.points_point[P_2][P_2_X] >= line.points_point[P_1][P_1_X]) &&
		   (line.points_point[P_2][P_2_Y] >= line.points_point[P_1][P_1_Y])) {
			printf("In quad I\n");
			points_imaginary[_X] = (line.points_point[P_1][P_1_X]-line.points_point[P_1][P_1_X]) + line.points_changeIn[_X];
			points_imaginary[_Y] = (line.points_point[P_2][P_2_Y]-line.points_point[P_1][P_1_Y]) - line.points_changeIn[_Y];
			
			xChange_power = pow(points_imaginary[_X]+(line.points_point[P_1][P_1_X]-line.points_point[P_1][P_1_X]) ,2);
			yChange_power = pow((line.points_point[P_1][P_1_Y]-line.points_point[P_1][P_1_Y])-points_imaginary[_Y] ,2);
			changeIn_total = xChange_power + yChange_power;
			if(changeIn_total < 0){
				changeIn_total = changeIn_total * (-1);
			}
			points_imaginary_distance = sqrt(changeIn_total);
			
			if(line.points_distence == 0)
				line.movement_angle = 0;
			else
				line.movement_angle = acos(points_imaginary_distance/line.points_distence);
			
		}else if((line.points_point[P_2][P_2_X] < line.points_point[P_1][P_1_X]) &&
		/**:)***/(line.points_point[P_2][P_2_Y] >= line.points_point[P_1][P_1_Y])){
			printf("In quad II\n");
			points_imaginary[_X] = (line.points_point[P_1][P_1_X] - line.points_point[P_1][P_1_X]) - line.points_changeIn[_X];
                        points_imaginary[_Y] = (line.points_point[P_2][P_2_Y]-line.points_point[P_1][P_1_Y]) - line.points_changeIn[_Y];	
			
			xChange_power = pow(points_imaginary[_X]+(line.points_point[P_1][P_1_X]-line.points_point[P_1][P_1_X]) ,2);
                        yChange_power = pow((line.points_point[P_1][P_1_Y]-line.points_point[P_1][P_1_Y])-points_imaginary[_Y] ,2);
                        changeIn_total = xChange_power + yChange_power;
                        if(changeIn_total < 0){
                                changeIn_total = changeIn_total * (-1);
                        }
                        points_imaginary_distance = sqrt(changeIn_total);

			if(line.points_distence == 0){
                                line.movement_angle = 0;
                        }else{
                                line.movement_angle = 180 * radianConverter - acos(points_imaginary_distance/line.points_distence);
			}
		}else if((line.points_point[P_2][P_2_X] <= line.points_point[P_1][P_1_X]) && 
		/**:)***/(line.points_point[P_2][P_2_Y] <  line.points_point[P_1][P_1_Y])) {
			printf("In quad III\n");
			points_imaginary[_X] = (line.points_point[P_2][P_2_X]-line.points_point[P_1][P_1_X]) + line.points_changeIn[_X];
                        points_imaginary[_Y] = (line.points_point[P_1][P_1_Y]-line.points_point[P_1][P_1_Y]) - line.points_changeIn[_Y];

                        xChange_power = pow(points_imaginary[_X]+(line.points_point[P_1][P_1_X]-line.points_point[P_1][P_1_X]) ,2);
                        yChange_power = pow((line.points_point[P_1][P_1_Y]-line.points_point[P_1][P_1_Y])-points_imaginary[_Y] ,2);
                        changeIn_total = xChange_power + yChange_power;
                        if(changeIn_total < 0){
                                changeIn_total = changeIn_total * (-1);
                        }
                        points_imaginary_distance = sqrt(changeIn_total);

                        if(line.points_distence == 0){
                                line.movement_angle = 0;
                        }else{
                                line.movement_angle = 270 * radianConverter - acos(points_imaginary_distance/line.points_distence);
                        } 
		}else if((line.points_point[P_2][P_2_X] > line.points_point[P_1][P_1_X]) &&
		/**:)***/(line.points_point[P_2][P_2_Y] < line.points_point[P_1][P_1_Y])) {
			printf("In quad IV\n");
			points_imaginary[_X] = (line.points_point[P_2][P_2_X]-line.points_point[P_1][P_1_X]) - line.points_changeIn[_X];
                        points_imaginary[_Y] = (line.points_point[P_1][P_1_Y]-line.points_point[P_1][P_1_Y]) - line.points_changeIn[_Y];

                        xChange_power = pow(points_imaginary[_X]+(line.points_point[P_1][P_1_X]-line.points_point[P_1][P_1_X]) ,2);
                        yChange_power = pow((line.points_point[P_1][P_1_Y]-line.points_point[P_1][P_1_Y])-points_imaginary[_Y] ,2);
                        changeIn_total = xChange_power + yChange_power;
                        if(changeIn_total < 0){
                                changeIn_total = changeIn_total * (-1);
                        }
                        points_imaginary_distance = sqrt(changeIn_total);

                        if(line.points_distence == 0){
                                line.movement_angle = 0;
                        }else{
                                line.movement_angle = 360 * radianConverter - acos(points_imaginary_distance/line.points_distence);
                        }	
		}
		line.inRadians = true;
	}
}

void pointOrbit(float degree, char direction){
	degree = degree * (M_PI/180);
//	getCurrentAngle_R();
//	getPointsDist();
	float newAngle;

	if(direction == '+' && degree < 0){
		direction = '-';
		degree = degree * (-1);
	}else if(direction == '-' && degree < 0){
		direction = '+';
		degree = degree * (-1);
	}

	if(direction != '+' && direction != '-'){
		printf("invalid direction definition\n");

	}else if(direction == '+' && line.inRadians == true){
		newAngle = line.movement_angle + degree;
		if((newAngle) > 360*(M_PI/180)){
			while(newAngle > 360*(M_PI/180)){
				newAngle -= 360*(M_PI/180);
			}
		}
		if(newAngle == 360*(M_PI/180)){
			newAngle = 0;
                }
		
		line.points_point[P_2][P_2_X] = cos(newAngle) * line.points_distence + line.points_point[P_1][P_1_X];
		line.points_point[P_2][P_2_Y] = sin(newAngle) * line.points_distence + line.points_point[P_1][P_1_Y];
		line.movement_angle = newAngle;
	
	}else if(direction == '-' && line.inRadians == true){
		newAngle = line.movement_angle - degree;
		if(newAngle < 0){
			while(newAngle < 0){
				newAngle += 360*(M_PI/180);
			}
		}
		
		line.points_point[P_2][P_2_X] = cos(newAngle) * line.points_distence + line.points_point[P_1][P_1_X];
                line.points_point[P_2][P_2_Y] = sin(newAngle) * line.points_distence + line.points_point[P_1][P_1_Y];
		line.movement_angle = newAngle;
	}
}

void displayControls(void){
	if(vk.d){
              	pointOrbit(1, '+');
	}
	if(vk.a){
       	       pointOrbit(1, '-');
        }
	if(vk.i){
		enumerate_line_data();
	}
	glutPostRedisplay();
}

void display(void){	
	//getCurrentAngle_R();
	//enumerate_line_data();

	glClear(GL_COLOR_BUFFER_BIT/* | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT*/);
		glLoadIdentity();
                glBegin(GL_LINES);
               // glColor3f(1, 0, 0);
                        /* origin  */
                        glVertex2f(line.points_point[P_1][P_1_X], line.points_point[P_1][P_1_Y]);

                        /* point  */
                        glVertex2f(line.points_point[P_2][P_2_X], line.points_point[P_2][P_2_Y]);
                glEnd();
	glutSwapBuffers();
	//glutPostRedisplay();
}

void idle(void){
	//getPointsDist();
        //getCurrentAngle_R();
        //enumerate_line_data();
	displayControls();
	glutPostRedisplay();
}

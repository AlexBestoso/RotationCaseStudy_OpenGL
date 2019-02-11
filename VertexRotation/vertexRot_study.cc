#include "studyHeader.h"
	
int main(int argc, char *argv[]){
	system("clear");
	
	setPoints();	
	getPointsDist();
        getCurrentAngle_R();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	
	glutInitWindowSize(700, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Rotation Case Study");

	/*Optional features*/
	glClearColor(0.5, 0.5, 0.5, 1.0);
	glutSetKeyRepeat(GLUT_KEY_REPEAT_ON);

	glutDisplayFunc(display); 
	glutKeyboardUpFunc(keyboard_up);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard_down);		
	glutMainLoop();
	return 0;
}

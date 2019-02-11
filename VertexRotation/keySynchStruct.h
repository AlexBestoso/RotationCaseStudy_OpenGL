struct VirtualKeyboard{
	/*WASD controls*/
        bool w;
        bool a;
        bool s;
        bool d;
	
	/*0 - 9*/
	bool number_0;
	bool number_1;
	bool number_2;
	bool number_3;
	bool number_4;
	bool number_5;
	bool number_6;
	bool number_7;
	bool number_8;
	bool number_9;
	
	/* Space Bar */
	bool spacebar;

	/* IJKL keys */
	bool i;
	bool j;
	bool k;
	bool l;
}vk;

void keyboard_down(unsigned char key, int mouseX, int mouseY){
/* WASD Controls */
        if(key == 'w'){
                vk.w = true;
                glutPostRedisplay();

        }else if(key == 'a'){
                vk.a = true;
                glutPostRedisplay();

        }else if(key == 's'){
                vk.s = true;
                glutPostRedisplay();

        }else if(key == 'd'){
                vk.d = true;
                glutPostRedisplay();
/* Numbers 0 - 9 */       
	}else if(key == '0'){
        	vk.number_0 = true;
		glutPostRedisplay();	
	}else if(key == '1'){
		vk.number_1 = true; 
                glutPostRedisplay();
	}else if(key == '2'){
		vk.number_2 = true; 
                glutPostRedisplay();
	}else if(key == '3'){
		vk.number_3 = true; 
                glutPostRedisplay();
	}else if(key == '4'){
		vk.number_4 = true; 
                glutPostRedisplay();
	}else if(key == '5'){
		vk.number_5 = true; 
                glutPostRedisplay();
	}else if(key == '6'){
		vk.number_6 = true; 
                glutPostRedisplay();
	}else if(key == '7'){
		vk.number_7 = true; 
                glutPostRedisplay();
	}else if(key == '8'){
		vk.number_8 = true; 
                glutPostRedisplay();
	}else if(key == '9'){
		vk.number_9 = true; 
                glutPostRedisplay();
/* space bar */
	}else if(key == ' '){
		vk.spacebar = true;
		glutPostRedisplay();
/* arrow keys */
	}else if(key == 'i'){
		vk.i = true;
		glutPostRedisplay();
	}else if(key == 'l'){
		vk.l = true;
		glutPostRedisplay();
	}else if(key == 'k'){
		vk.k = true;
		glutPostRedisplay();
	}else if(key == 'j'){
		vk.j = true;
		glutPostRedisplay();
	}else{
		glutPostRedisplay();
	}

	
}

void keyboard_up(unsigned char key, int mouseX, int mouseY){
        if(key == 'w'){
                vk.w = false;
                glutPostRedisplay();

        }else if(key == 'a'){
                vk.a = false;
                glutPostRedisplay();

        }else if(key == 's'){
                vk.s = false;
                glutPostRedisplay();

        }else if(key == 'd'){
                vk.d = false;
                glutPostRedisplay();
        /* Numbers 0 - 9 */
        }else if(key == '0'){
                vk.number_0 = false; 
                glutPostRedisplay();
        }else if(key == '1'){
                vk.number_1 = false;
                glutPostRedisplay();
        }else if(key == '2'){
                vk.number_2 = false;
                glutPostRedisplay();
        }else if(key == '3'){
                vk.number_3 = false;
                glutPostRedisplay();
        }else if(key == '4'){
                vk.number_4 = false;
                glutPostRedisplay();
        }else if(key == '5'){
                vk.number_5 = false;
                glutPostRedisplay();
        }else if(key == '6'){
                vk.number_6 = false;
                glutPostRedisplay();
        }else if(key == '7'){
                vk.number_7 = false;
                glutPostRedisplay();
        }else if(key == '8'){
                vk.number_8 = false;
                glutPostRedisplay();
        }else if(key == '9'){
                vk.number_9 = false;
                glutPostRedisplay();
/* space bar */
        }else if(key == ' '){
		vk.spacebar = false;
                glutPostRedisplay();
/* IJKL keys */
        }else if(key == 'i'){
                vk.i = false;
                glutPostRedisplay();
        }else if(key == 'l'){
                vk.l = false;
                glutPostRedisplay();
        }else if(key == 'k'){
                vk.k = false;
                glutPostRedisplay();
        }else if(key == 'j'){
                vk.j = false;
                glutPostRedisplay();
        }else{
                glutPostRedisplay();
        }
}

  /* ------------ GAME OVER ------------ */
    else if(page==2){

        glColor3f(1,0,0);

        drawText(230,430,"GAME OVER");

        char s[50];
        char h[50];

        sprintf(s,"Final Score: %d",score);
        sprintf(h,"High Score: %d",highScore);

        glColor3f(1,1,1);

        drawText(220,360,s);
        drawText(220,320,h);

        drawText(180,260,"Press M for Menu");
        drawText(180,230,"Press Q to Exit");
    }

    glutSwapBuffers();
}

/* ------------ TIMER ------------ */
void timer(int v){

    if(page==1 && !pauseGame){

        timeLeft--;

        if(timeLeft<=0){

            if(score>highScore)
                highScore = score;

            page = 2;

            glutPostRedisplay();
        }
    }

    glutTimerFunc(1000,timer,0);
}

/* ------------ UPDATE ------------ */
void update(int v){

    glutPostRedisplay();

    glutTimerFunc(16,update,0);
}

/* ------------ KEYBOARD ------------ */
void keyboard(unsigned char key,int x,int y){

    // Convert uppercase to lowercase
    if(key>='A' && key<='Z')
        key = key + 32;

    /* ------------ MENU ------------ */
    if(page==0){

        if(key=='1'){

            score = 0;
            timeLeft = 60;
            pauseGame = 0;

            newObject();

            page = 1;
        }

        else if(key=='2'){

            page = 1;
        }

        else if(key=='3'){

            printf("High Score: %d\n",highScore);
        }

        else if(key=='4'){

            exit(0);
        }
    }

    /* ------------ GAME ------------ */
    else if(page==1){

        if(key=='a')
            basket_x -= 20;

        else if(key=='d')
            basket_x += 20;

        else if(key=='p')
            pauseGame = !pauseGame;

        else if(key=='q')
            exit(0);

        // Basket limit
        if(basket_x < 0)
            basket_x = 0;

        if(basket_x > 540)
            basket_x = 540;
    }

    /* ------------ GAME OVER ------------ */
    else if(page==2){

        if(key=='m'){

            page = 0;
        }

        else if(key=='q'){

            exit(0);
        }
    }

    glutPostRedisplay();
}

/* ------------ MAIN ------------ */
int main(int argc,char** argv){

    srand(time(0));

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(width,height);

    glutCreateWindow("Catch The Eggs");

    glutSetKeyRepeat(GLUT_KEY_REPEAT_ON);

    init();

    newObject();

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    glutTimerFunc(1000,timer,0);

    glutTimerFunc(16,update,0);

    glutMainLoop();

    return 0;
}

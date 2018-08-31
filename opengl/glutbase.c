/*se.c -- glut base application
 * last modification: aug. 14, 2007
 *
 * Copyright (c) 2005-2007 David HENRY
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * gcc -Wall -ansi -lGL -lGLU -lglut glutbase.c -o glutbase
 */

#include <GL/glut.h>
#include <stdlib.h>
#include <string.h>


/* Keyboard */
struct keyboard_input_t
{
  unsigned char keymap[256];
  int special[256];
  int modifiers;

} keyboard;

/* Mouse */
struct mouse_input_t
{
  int buttons[3];
  int x, y;

} mouse;

/* Timer */
struct glut_timer_t
{
  double current_time;
  double last_time;

} timer;

/* Camera vectors */
struct Vector3d
{
  float x, y, z;

} rot, eye;


/**
 * Application termination
 */
static void
cleanup ()
{
}

/**
 * Application initialisation. Setup keyboard input,
 * mouse input, timer, camera and OpenGL.
 */
static void
init ()
{
  /*
   * Application initialization
   */

  /* Init keyboard */
  memset (keyboard.keymap, 0, 256);
  memset (keyboard.special, 0, 256);

  /* Init mouse */
  mouse.buttons[GLUT_LEFT_BUTTON] = GLUT_UP;
  mouse.buttons[GLUT_MIDDLE_BUTTON] = GLUT_UP;
  mouse.buttons[GLUT_RIGHT_BUTTON] = GLUT_UP;
  mouse.x = 0;
  mouse.y = 0;

  /* Init timer */
  timer.current_time = 0;
  timer.last_time = 0;

  /* Init camera input */
  rot.x = 0.0f;   eye.x = 0.0f;
  rot.y = 0.0f;   eye.y = 0.0f;
  rot.z = 0.0f;   eye.z = 7.0f;

  /*
   * OpenGL initialization
   */
  glClearColor (0.5f, 0.5f, 0.5f, 1.0f);
  glShadeModel (GL_SMOOTH);

  glEnable (GL_DEPTH_TEST);
  glEnable (GL_LIGHTING);
  glEnable (GL_LIGHT0);
}

/**
 * GLUT's reshape callback function.
 * Update the viewport and the projection matrix.
 */
static void
reshape (int w, int h)
{
  if (h == 0)
    h = 1;

  glViewport (0, 0, (GLsizei)w, (GLsizei)h);

  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective (45.0, (GLfloat)w/(GLfloat)h, 0.1, 1000.0);

  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity ();

  glutPostRedisplay ();
}

/**
 * Timer update
 */
static void
updateTimer (struct glut_timer_t *t)
{
  t->last_time = t->current_time;
  t->current_time = (double)glutGet (GLUT_ELAPSED_TIME) * 0.001f;
}

/**
 * Keyboard input handling
 */
static void
handleKeyboard (struct keyboard_input_t *k)
{
  /*
   * Handle here continuous actions when
   * a key is pressed (like moving the camera)
   */

  /*
  if (k->keymap['yourkey'])
    do_something ();
  */
}

/**
 * GLUT's display callback function.
 * Render the main OpenGL scene.
 */
static void
display ()
{
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity ();

  /* Camera rotation */
  glTranslated (-eye.x, -eye.y, -eye.z);
  glRotated (rot.x, 1.0f, 0.0f, 0.0f);
  glRotated (rot.y, 0.0f, 1.0f, 0.0f);
  glRotated (rot.z, 0.0f, 0.0f, 1.0f);

  /* Draw utah-teapot */
  glutSolidTeapot (1.0f);

  glutSwapBuffers ();
}

/**
 * GLUT's Key press callback function.
 * Called when user press a key.
 */
static void
keyPress (unsigned char key, int x, int y)
{
  static int lightOn = 1;

  /* Update key state */
  keyboard.keymap[key] = 1;

  /*
   * Handle here ponctual actions when
   * a key is pressed (like toggle ligthing)
   */

  /* Escape */
  if (key == 27)
    exit (0);

  /* 'l': toggle light */
  if (key == 'l')
    lightOn = !lightOn;

  if (lightOn)
    glEnable (GL_LIGHTING);
  else
    glDisable (GL_LIGHTING);

  glutPostRedisplay ();
}

/**
 * GLUT's Key up callback function.
 * Called when user release a key.
 */
static void
keyUp (unsigned char key, int x, int y)
{
  keyboard.keymap[key] = 0;
}

/**
 * GLUT's Key press callback function.
 * Called when user press a special key.
 */
static void
specialKeyPress (int key, int x, int y)
{
  keyboard.special[key] = 1;
}

/**
 * GLUT's key up callback function.
 * Called when user release a special key.
 */
static void
specialKeyUp (int key, int x, int y)
{
  keyboard.special[key] = 0;
}

/**
 * GLUT's mouse motion callback function.
 * Called when the user move the mouse. Update the
 * camera.
 */
static void
mouseMotion (int x, int y)
{
  if (mouse.buttons[GLUT_RIGHT_BUTTON] == GLUT_DOWN)
    {
      /* Zoom */
      eye.z += (x - mouse.x) * 0.1;
    }
  else if (mouse.buttons[GLUT_LEFT_BUTTON] == GLUT_DOWN)
    {
      if (keyboard.modifiers & GLUT_ACTIVE_SHIFT)
	{
	  /* Translation */
	  eye.x -= (x - mouse.x) * 0.02;
	  eye.y += (y - mouse.y) * 0.02;
	}
      else
	{
	  /* Rotation */
	  rot.x += (y - mouse.y);
	  rot.y += (x - mouse.x);
	}
    }

  mouse.x = x;
  mouse.y = y;

  glutPostRedisplay ();
}

/**
 * GLUT's mouse button callback function.
 * Called when the user press a mouse button. Update mouse
 * state and keyboard modifiers.
 */
static void
mouseButton (int button, int state, int x, int y)
{
  /* Update key modifiers */
  keyboard.modifiers = glutGetModifiers ();

  /* Update mouse state */
  mouse.buttons[button] = state;
  mouse.x = x;
  mouse.y = y;
}

/**
 * GLUT's idle callback function.
 * Continuously called. Perform background processing tasks.
 */
static void
idleVisible ()
{
  /* Update the timer */
  updateTimer (&timer);

  /* Handle keyboard input */
  handleKeyboard (&keyboard);
}

/**
 * GLUT's window status callback function.
 * Called when the status of the window changes.
 */
static void
windowStatus (int state)
{
  /* Disable rendering and/or animation when the
     window is not visible */
  if ((state != GLUT_HIDDEN) &&
      (state != GLUT_FULLY_COVERED))
    {
      glutIdleFunc (idleVisible);
    }
  else
    {
      glutIdleFunc (NULL);
    }
}

/**
 * This is the main program.
 */
int
main (int argc, char *argv[])
{
  /* Initialize GLUT */
  glutInit (&argc, argv);

  /* Create an OpenGL window */
  glutInitDisplayMode (GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize (640, 480);
  glutCreateWindow ("Simple glut window");

  /* Initialize application */
  atexit (cleanup);
  init ();

  /* Setup GLUT's callback functions */
  glutReshapeFunc (reshape);
  glutDisplayFunc (display);
  glutKeyboardFunc (keyPress);
  glutKeyboardUpFunc (keyUp);
  glutSpecialFunc (specialKeyPress);
  glutSpecialUpFunc (specialKeyUp);
  glutMotionFunc (mouseMotion);
  glutMouseFunc (mouseButton);
  glutWindowStatusFunc (windowStatus);
  glutIdleFunc (idleVisible);

  /* Enter the main loop */
  glutMainLoop ();

  return 0;
}

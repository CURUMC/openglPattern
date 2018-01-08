#include "GL/glut.h"
#include <iostream>
#include"CirEff.h"
#include <Windows.h>
#include <list>

#define W (800)
#define H (600)

std::list<CirEff*> list;
std::list<CirEff*> list2;
Point g_mouse;


GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);
void Mouse(int x, int y);
void Mouse(int button, int state, int x, int y);
void Keyboard(unsigned char key, int x, int y);
void Timerfunction(int value);
void Init();

void pluslist();

void main(int argc, char *argv[])
{
	//�ʱ�ȭ �Լ���
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // ���÷��� ��� ����
	glutInitWindowPosition(100, 100); // �������� ��ġ����
	glutInitWindowSize(800, 600); // �������� ũ�� ����
	glutCreateWindow("Example"); // ������ ���� (������ �̸�)
	glutDisplayFunc(drawScene); // ��� �Լ��� ����
	glutReshapeFunc(Reshape); // �ٽ� �׸��� �Լ��� ����
	Init();
	glutTimerFunc(16, Timerfunction, 1);
	glutMouseFunc(Mouse);

	glutPassiveMotionFunc(Mouse);
	glutKeyboardFunc(Keyboard);



	glutMainLoop();
}


void Mouse(int x, int y)
{

	g_mouse.x = x;
	g_mouse.y = y;


}

void pluslist() {
	CirEff * tmp = new CirEff;
	tmp->Init(g_mouse);
	list.emplace_back(tmp);
	if (list.size() > 10) {
		//list.pop_front();
		list.front()->Off();
		list2.push_back(list.front());
		list.pop_front();
	}
}

void Timerfunction(int value) {
	for (auto&q : list) {
		q->Update();
	}
	for (auto&q : list2) {
		q->Update();
	}

	for (auto&q : list2) {
		if (q->GetisDie())
		{
			delete q;
			q = nullptr;
		}

	}
	list2.remove_if([](const CirEff* tmp) {return tmp==nullptr; });


	glutPostRedisplay();
	glutTimerFunc(16, Timerfunction, 1);
}
void Mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON&&state == GLUT_UP) {
		pluslist();
	}


	g_mouse.x = x;
	g_mouse.y = y;
	glutPostRedisplay();
}

void Init() {


	list.clear();


}

// ������ ��� �Լ�
GLvoid drawScene(GLvoid)
{
	glClearColor(0.f, 0.f, 0.f, 0.f); // �������� ������� ����
	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
								  // ���� �����ϰ� �簢�� �׸���

	for (const auto & q : list2) {
		q->Draw();
	}

	for (const auto & q : list) {
		q->Draw();
	}


	glFlush(); // ȭ�鿡 ����ϱ�
}
GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(0, 800, 600, 0, -1, 1);
}

void Keyboard(unsigned char key, int x, int y)
{

}

#include "AppController.h"

int main(void)
{
	AppController* appController = AppController_new();
	// ���ο� AppController ��ü ����.
	AppController_run(appController); // AppController ���� run �Լ� ����.
	AppController_delete(appController); // AppController �� �޸𸮿��� �����Ѵ�.
	system("pause");
	// ���α׷��� ����Ǳ� ���� �Ͻ������Ѵ�.
	return 0;
}
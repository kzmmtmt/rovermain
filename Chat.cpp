#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include "chat.h"
#include "utils.h"
using namespace std;

//20170630�}���`�[�Y�ǉ��`���b�g�v���O����
//������ς��󂯂Ƃ�server�̃Z�b�g�A�b�v
bool Server::init(int cl_ip)
{
	//�\�P�b�g�̍쐬
	//�����̓A�h���X�t�@�~���A�\�P�b�g�^�C�v�A�v���g�R��
	sock0 = socket(AF_INET, SOCK_STREAM, 0);

	//sock��-1��Ԃ����玸�s
	if (sock < 0)
		{
			//�G���[��\�����鏈��
			perror("socket�̃G���[���o�܂���");
			printf("%d\n", errno);
			return 1;
		}
		//�\�P�b�g�̐ݒ�
		addr.sin_family = AF_INET;
		addr.sin_port = htons(12345);
		addr.sin_addr.s_addr = INADDR_ANY;
		bind(sock0, (struct sockaddr *)&addr, sizeof(addr));

		//TCP�N���C�A���g����̐ڑ��v����҂Ă��Ԃɂ���
		listen(sock0, 5);

		return true;
}
//���x���ڑ��v����t�����݂�
void Server::update(double elapsedSeconds)
{
	//TCP�N���C�A���g����̐ڑ��v�����󂯕t����
	len = sizeof(client);
	sock = accept(sock0, (struct sockaddr *)&client, (socklen_t *)&len);
}
//sock�������[�I���i�d�͏���y���炵���H�j
void Server::clean();
{
	//TCP�Z�b�V�����̏I��
	close(sock);
	//listen����socket�̏I��
	close(sock0);
	mes = NULL
}
void Server::onCommand(const std::vector<std::string>& args)
{
	switch(args.size())
	{
		case 2:
		if(args[1].compare(""))
	}

}

Server::Server():
{
	setName("chat");
	setPriority(TASK_)
}
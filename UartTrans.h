/***********************************************************************
 * Module:  UartTrans.h
 * Author:  Thinkpad
 * Modified: 2015-04-29 14:14:02
 * Purpose: Declaration of the class UartTrans
 * Comment: ���ڲ�����
 ***********************************************************************/

//ͷ�ļ�����
#include <stdio.h> 	//��׼�����������
#include <cstdlib>	//��׼�����ⶨ��
#include <unistd.h>	//Unix��׼��������
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 	//�ļ����ƶ���
#include <termios.h>	//POSIX�жϿ��ƶ���
#include <cstring>
#include <string>
#if !defined(__Veg_UartTrans_h)
#define __Veg_UartTrans_h

class UartTrans
{
	public:
		/* �򿪴��� */
		int UartOpen(int UartNo, int baudRate, std::string &errStr);

		/* ���ڷ��� */
		int UartSend(char *buf, int len, std::string &errStr);
		/* ���ڽ��� */
		int UartRecevie(char *buf, int len, std::string &errStr);
		/* �رմ��� */
		int UartColse(std::string &errStr);
	private:
		int fd;		//���ڵı�ʶ��
};



/* �򿪴��� */
int UartTrans::UartOpen(int UartNo, int baudRate, std::string &errStr)
{
	printf("open uart......\n");
	//O_NOCTTY��������Linux������򲻻��Ϊ�������նˡ�
	//O_NDELAY��������Linux������򲻹���DCD�ź�
	char* serial_device = new char;
	if(UartNo==0) strcpy(serial_device,"/dev/ttyS0");
	else if (UartNo == 1) strcpy(serial_device,"/dev/ttyS1");
	this->fd = open(serial_device, O_RDWR | O_NOCTTY | O_NDELAY);
	if (this->fd == -1)
	{
		//���ܴ򿪴���
		errStr = "open_port: Unable to open ";
		errStr += serial_device;
//		perror("open_port: Unable to open /dev/ttyS0 -");
		return(0);
	}
	else
		fcntl(this->fd, F_SETFL, 0);
	delete(serial_device);

	//��ʼ���岨����
	struct termios Opt;	//����termios�ṹ
	if (tcgetattr(this->fd, &Opt) != 0)
	{
		errStr="tcgetattr fd failly";
		return 0;
	}
	tcflush(this->fd, TCIOFLUSH);
	cfsetispeed(&Opt, baudRate);
	cfsetospeed(&Opt, baudRate);
	/*tcsetattr������־��
	TCSANOW������ִ�ж����ȴ����ݷ��ͻ��߽�����ɡ�
	TCSADRAIN���ȴ��������ݴ�����ɺ�ִ�С�
	TCSAFLUSH��Flush input and output buffers and make the change
	*/
	if (tcsetattr(this->fd, TCSANOW, &Opt) != 0)
	{
		errStr="tcsetattr fd failly";
		return 0;
	}
	tcflush(this->fd, TCIOFLUSH);
	//������żУ�顪��Ĭ��8������λ��û��У��λ

	Opt.c_cflag &= ~PARENB;
	Opt.c_cflag &= ~CSTOPB;
	Opt.c_cflag &= ~CSIZE;
	Opt.c_cflag |= CS8;

	//������һЩ����
	//ԭʼ���룬�����ַ�ֻ�Ǳ�ԭ�ⲻ���Ľ���
	Opt.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
	//�����������Ч����ΪӲ��û��Ӳ�������ƣ����ԾͲ���Ҫ����
	Opt.c_iflag &= ~(IXON | IXOFF | IXANY);
	//ԭʼ�����ʽ����ͨ����c_oflag������OPOSTѡ����ѡ��
	Opt.c_oflag |= ~OPOST;
	//VMIN����ָ����ȡ����С�ַ����������������Ϊ0����ôVTIMEֵ���ָ��ÿ���ַ���ȡ�ĵȴ�ʱ�䡣
	Opt.c_cc[VTIME] = 0;
	Opt.c_cc[VMIN] = 0;
	Opt.c_oflag &= ~(ONLCR | OCRNL);
	Opt.c_iflag &= ~(ICRNL | INLCR);
	tcflush(this->fd, TCIOFLUSH);

	printf("open uart succeed!\n");
	return 1;

}
/* ���ڷ��� */
int UartTrans::UartSend(char *buf, int len, std::string &errStr)
{
	printf("send data.......\n");
	//��ȡʵ�ʴ������ݵĳ���
	int nread = 0;
	nread = write(this->fd, buf, len);
	if (nread <= 0)
	{
		errStr = "send data failly";
		return 0;
	}
	else
		printf("send data succeed,data length=%d\n",nread);
	return 1;
}
/* ���ڽ��� */
int UartTrans::UartRecevie(char *buf, int len, std::string &errStr)
{
	printf("receive data.....\n");
	bzero(buf, sizeof(buf)); 
	len = read(this->fd, buf, len);
	if (len < 0)
	{
		errStr = "Receiving data failly";
		return 0;
	}
	printf("data receive succeed,data length=%d\n",len);
	return 1;
}
/* �رմ��� */
int UartTrans::UartColse(std::string &errStr)
{
	printf("close uart...\n");
	if (close(this->fd) == 0)
		return 1;
	else
	{
		errStr = "close_port:Unable to close uart";
		return 0;
	}
}

#endif

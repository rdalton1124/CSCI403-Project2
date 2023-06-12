#ifndef MESSAGE_Q_H
#define MESSAGE_Q_H
#include<sys/msg.h>

class message_q {
	public:
		message_q(key_t);
		~message_q();
		int find(key_t);
		int getMaxSize();
		void setMaxSize(int);
		void setOwnerID(int);
		int getOwnerID();
		int getQID();
		time_t getLastSendTime();
		time_t getLastRecTime();
		pid_t getLastSendPID();
		pid_t getLastRecPID();
		int getNumMsgs();
		int send(int, void*);
		int recv(long, int, void*, int);
	private:
		int qid;
		msqid_ds g;
		msqid_ds s;
		key_t key;
};
#endif
#include<sys/msg.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include "message_q.h"


message_q::message_q(key_t k) {
	key = k;
	//create the queue
	qid = msgget(key, IPC_CREAT);
}
message_q::~message_q() {
//delete the queue
	msgctl(qid, IPC_RMID, NULL);
	delete &g;
	delete &s;
}
//finds an id given a key.
int message_q::find(key_t other) {
	return msgget(other, 0);
}
//getters and sets for max size.
int message_q::getMaxSize() {
	msgctl(qid, IPC_STAT, &g);
	return (int) g.msg_qbytes;
}
void message_q::setMaxSize(int bytes) {
	msgctl(qid, IPC_STAT, &s); //copy current msqid ds into s
	s.msg_qbytes = (ushort) bytes; //update max bytes of s
	msgctl(qid, IPC_SET, &s); //set the current msqid ds to s
}

//getters and setters for owner id
void message_q::setOwnerID(int newID) {
	msgctl(qid, IPC_STAT, &s); //set s = current msqid ds
	s.msg_perm.uid = newID; //update s
	msgctl(qid, IPC_SET, &s); //set msqid ds = s
}
int message_q::getOwnerID() {
	msgctl(qid, IPC_STAT, &g);
	return g.msg_perm.uid;
}
//gets the queue id.
int message_q::getQID() {
	//return queue id
	return qid;
}
//time getters
time_t message_q::getLastSendTime() {
	msgctl(qid, IPC_STAT, &g);
	return g.msg_stime;
}
time_t message_q::getLastRecTime() {
	msgctl(qid, IPC_STAT, &g);
	return g.msg_rtime;
}
//pid getters
pid_t message_q::getLastSendPID() {
	msgctl(qid, IPC_STAT, &g);
	return g.msg_lspid;
}
pid_t message_q::getLastRecPID() {
	msgctl(qid, IPC_STAT, &g);
	return g.msg_lrpid;
}
//get number of messages
int message_q::getNumMsgs() {
	msgctl(qid, IPC_STAT, &g);
	return g.msg_qnum;
}
int message_q::send(int pid, void *msg) {
	//send message
	size_t size = sizeof(&msg) - sizeof(long);
	return msgsnd(pid, msg, size, 0);
}
int message_q::recv(long type, int pid, void *msg, int len) {
	return (int) msgrcv(pid, msg, (size_t) len, type, NULL);
}
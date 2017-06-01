#ifndef _MSGSEND_H_
#define _MSGSEND_H_

class MESSAGE_SEND
{
public:
	void Normal(int aIndex, char * Message,...);
	void NormalMap(char Map, char * Message,...);
	void NormalAll(char * Message,...);
	void Announce(int aIndex, char *Message,...);
	void AnnounceMap(char Map, char * Message,...);
	void AnnounceAll(char * Message,...);
	void Post(int aIndex,char* Message, ...);

};

extern MESSAGE_SEND Send;

#endif
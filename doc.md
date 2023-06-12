# Purpose 
  - This is code that I wrote for CSCI 403, Intro to Operating Systems (Spring2022) 
  - The purpose was to encapsulate Linux's sys/msg.h's functionality in a message queue program 
  - msg.h is a program which 
  - The header and the C++ file are included. There were 2 more classes that used the message queue, but they are now lost 
  - This project received a 7.3 / 10. Lost points were due to wrong report format and failure to attach code output to report. 
# Functions
## Constructor 
  - Sets key 
  - Creates queue and sets QID 
## Destructor 
  - Removes settings using msgctl
  - Deletes s and g. 
## find 
  - Calls msg.h's msgget 
## getMaxSize
  - Returns the max message size. 
  - The msgctl command retreives the settings and stores them into g, a struct which contains the configurations 
  - Returns max size from g
## setMaxSize 
  - Sets the maximum message size in bytes 
  - First msgctl statement copies the configs into s. 
  - Updates s's max size 
  - Second msgctl statement sets the settings to the updated s. 
## setOwnerID
  - Sets the owenrID 
  - Uses the same process as setMaxSize but updates the ownerID instead
## getOwnerID
  - Gets the ownerID 
  - Uses the same process as getMaxSize, but returns ownerID instead 
## getQID
  - Returns the queue ID 
## getLastSendTime, getLastRecTime, getLastSendPID, getLastRecPID, getNumMessages
  - uses msgctl and returns the relevant information 
## send 
  - Send message 
## recv 
  - Receive message 
  - Just calls msg.h's msgrcv function 

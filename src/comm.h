#pragma once
#define KEY_DATA 5 // DELETE ME
#define MAX_NAME_LEN 60
  
#define LIST_RESPONSE "LIST_RESPONSE"
#define TASK "TASK"
  
#define POMO_COMPLETE "POMO_COMPLETE"
#define LIST_REQUEST "LIST_REQUEST"

typedef struct {
  int t_id;
  char name[MAX_NAME_LEN];
  int nTarget;
  int nCompleted;
} task_t;
  
task_t** get_tasks();

int getNTtasks();

task_t* get_task(int index);

void free_tasks();
  
/*
  When called, signals the iOS app that a pomo 
  has been completed for the task with id t_id
*/
void pomo_completed(int t_id);

void list_request();

void inbox_received_callback(DictionaryIterator *iterator, void *context);

void inbox_dropped_callback(AppMessageResult reason, void *context);

void outbox_failed_callback(DictionaryIterator *iterator, AppMessageResult reason, void *context);

void outbox_sent_callback(DictionaryIterator *iterator, void *context);

void init_comm();
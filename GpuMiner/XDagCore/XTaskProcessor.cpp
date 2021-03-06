#include "XTaskProcessor.h"


XTaskProcessor::XTaskProcessor()
{
    //_taskIndex = -1;
    _taskCount = 0;
}


XTaskProcessor::~XTaskProcessor()
{
}

XTaskWrapper* XTaskProcessor::GetNextTask()
{
    //int index = _taskIndex > 1 ? 0 : _taskIndex + 1;
    //return &_tasks[index];
    return &_tasks[(_taskCount + 1) % 2];
}

XTaskWrapper* XTaskProcessor::GetCurrentTask()
{
    if(_taskCount <= 0)
    {
        return NULL;
    }

    //_taskMutex.lock();
    //XTaskWrapper* task = &_tasks[_taskIndex];
    XTaskWrapper* task = &_tasks[_taskCount % 2];
    //_taskMutex.unlock();
    return task;
}

void XTaskProcessor::SwitchTask()
{
    //TODO: resolve runtime error
    //_taskMutex.lock();
    //if(++_taskIndex > 2)
    //{
    //    _taskIndex = 0;
    //}
    ++_taskCount;
    //_taskMutex.unlock();
}

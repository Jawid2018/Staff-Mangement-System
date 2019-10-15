#ifndef BASEVIEW_H
#define BASEVIEW_H

template <class T>
class BaseView
{
    public:
    //Virtual function. This function should be implemented in drived class.
    virtual T getDataFromConsole();
    virtual void printDataToConsole(T);

};

#endif // BASEVIEW_H

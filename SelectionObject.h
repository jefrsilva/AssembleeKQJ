#ifndef __selectionobject__
#define __selectionobject__

namespace Engine {

    /**
     * \class SelectionObject
     * \author Jeferson Rodrigues da Silva
     * \date 12/09/2009
     * \file SelectionObject.h
     * \brief 
     */
    class SelectionObject {
        
    private:
        int type;
        void *data;

    public:
        SelectionObject();
        SelectionObject(int type, void *data);
        SelectionObject(const SelectionObject &object);
        ~SelectionObject();
        
        int getType();
        void *getData();

    };

}

#endif // __selectionobject__

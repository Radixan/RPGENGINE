
#ifndef __ABSTRACTSCENE_HPP__
#define __ABSTRACTSCENE_HPP__

class AbstractScene {
    public:
        virtual void            Init            () = 0;
        virtual void            Update          () = 0;
        virtual void            Render          () = 0;
        virtual void            Delete          () = 0;

};

#endif // __ABSTRACTSCENE_HPP__

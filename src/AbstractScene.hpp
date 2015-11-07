
#ifndef __ABSTRACTSCENE_HPP__
#define __ABSTRACTSCENE_HPP__

class AbstractScene {
    public:
        virtual void            Update          () = 0;
        virtual void            Render          () = 0;

        virtual                 ~AbstractScene  (){}

};

#endif // __ABSTRACTSCENE_HPP__

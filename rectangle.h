#ifndef RECTANGLE_H
#define RECTANGLE_H

namespace SDK {


    /**
     *  @brief  仅表示矩形框，只有一般矩形框的基本属性
     *  @author lynn
     *  @version 1.00 2017-11-20 lynn
     *                note:create it
     */
    class Rectangle
    {
    public:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1.访存函数
        double getXPos() { return this->m_xPos; }
        void setXPos(double xPos) { this->m_xPos = xPos; }

        double getYPos() { return this->m_yPos; }
        void setYPos(double yPos) { this->m_yPos = yPos; }

        double getWidth() { return this->m_width; }
        void setWidth(double width) { this->m_width = width; }

        double getHeight() { return this->m_height; }
        void setHeight(double height) { this->m_height = height; }

    private:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.成员变量
        double m_xPos;         //矩形在x坐标上的位置
        double m_yPos;         //矩形在y坐标上的位置
        double m_width;        //矩形的宽度
        double m_height;       //矩形的高度
    };

}

#endif // RECTANGLE_H

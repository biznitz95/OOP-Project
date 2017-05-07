#ifndef RECT_H
#define RECT_H

class Rect {
	private:
		float x, y;
		float w, h;
		bool col;

	public:
		Rect(float x, float y, float w, float h);
		void build();
		void set(char type, float temp);
		float get(char type);
		bool contains(float x, float y);
		void change(bool temp);
		~Rect();
};
#endif
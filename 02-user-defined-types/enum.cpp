enum class Color {red, blue, green};
enum class Traffic_light {green, yellow, red};

Color col = Color::red;
Traffic_light light = Traffic_light::red;

Traffic_light & operator++(Traffic_light & t)
{
    switch (t)
    {
    case Traffic_light::green:  return t = Traffic_light::yellow;
    case Traffic_light::yellow:  return t = Traffic_light::red;
    case Traffic_light::red:  return t = Traffic_light::green;
    }
}



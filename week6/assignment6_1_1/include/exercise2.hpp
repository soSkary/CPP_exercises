#ifndef EXERCISE_2
#define EXERCISE_2

enum class order_status
{
    ordered,
    packaged,
    preparing_shipment,
    shipped,
    delivered

};


struct State_machine
{
    order_status current_status;

    void print_status() const;
    void create_order();
    void advance_status();
};

#endif

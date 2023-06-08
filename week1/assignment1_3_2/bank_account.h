#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

struct Bank_account
{
private:
    unsigned int m_account_id{};
    double m_money{};
    

public:
    Bank_account(const double money = 0.0)
        :  m_money{money}
    {
        static unsigned int account_id{ 0 };
        m_account_id = account_id++;
    }


    unsigned int get_id() { return m_account_id; };
    const double get_balance() { return m_money; };
    void deposit_money();
    void deposit_money(const double money);
    int withdraw_money();
    void display_balance();
    
    //void create_log();
        
};

#endif

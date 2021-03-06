#include <bts/client/client.hpp>
#include <bts/cli/cli.hpp>
#include <bts/lotto/lotto_cli.hpp>

#include <iostream>
#include <sstream>
#include <iomanip>

namespace bts { namespace lotto {

using namespace client;

lotto_cli::lotto_cli( const client_ptr& c )
: bts::cli::cli(c)
{
}

lotto_cli::~lotto_cli()
{
}

void lotto_cli::print_help(){
    std::cout<<"Lotto Commands\n";
    std::cout<<"-------------------------------------------------------------\n";
    std::cout<<"buy_ticket AMOUNT UNIT [LUCKY_NUMBER] [ODDS] - buy tickets for specific lucky number with some odds\n";
    std::cout<<"-------------------------------------------------------------\n";

    cli::print_help();
}
void lotto_cli::process_command( const std::string& cmd, const std::string& args ){
    std::stringstream ss(args);

    if( cmd == "buy_ticket" ) {
        std::string line;
        // TODO: process buy lotto ticket commands
        std::string base_str,at;
        double      amount;
        // TODO: maybe lucky_number and odds should not be optional?
        uint16_t    lucky_number;
        uint16_t    odds;
        std::string unit;
        ss >> amount >> unit >> lucky_number >> odds;
        asset::type base_unit = fc::variant(unit).as<asset::type>();
        asset       amnt = asset(amount,base_unit);

        auto required_input = amnt;
        // TODO: get current balance
        asset curr_bal = asset::zero();

        //std::cout<<"current balance: "<< to_balance( curr_bal.amount.high_bits() ) <<" "<<fc::variant(required_input.unit).as_string()<<"\n"; 
        //std::cout<<"total price: "<< to_balance(required_input.amount.high_bits()) <<" "<<fc::variant(required_input.unit).as_string()<<"\n"; 

        if( required_input > curr_bal )
        {
            std::cout<<"Insufficient Funds\n";
        }
        else
        {
            std::cout<<"submit order? (y|n): ";
            std::getline( std::cin, line );
            if( line == "yes" || line == "y" )
            {
                // TODO: call wallet to buy the ticket,
                // main_thread->async( [=](){ c->buy(required_input,pr); } ).wait();
                std::cout<<"order submitted\n";
            }
            else
            {
                std::cout<<"order canceled\n";
            }
        }
    }
    else
    {
        cli::process_command(cmd, args);
    }
}
            
void lotto_cli::list_transactions( uint32_t count ){
    // TODO: list lotto related transactions
    cli::list_transactions(count);
}
void lotto_cli::get_balance( uint32_t min_conf, uint16_t unit ){
    // TODO: list lotto related balances
    cli::get_balance(min_conf, unit);
}

}}
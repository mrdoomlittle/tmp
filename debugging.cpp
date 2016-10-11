# ifndef ARDUINO

/* Created and Designed by MrDoomLittle
* Github URL: https://github.com/mrdoomlittle
* Email Addr: doctordoomlittle@gmail.com
* For Current Infomation about This Project
* See the File Called: ( INFOMATION )
*/

# include "io_service.hpp"

# include <boost/cstdint.hpp>

# include "bitset.hpp"

# include <iostream>

# include "dynamic_array.hpp"
# include "carg_filter.hpp"
# include "data_packet.hpp"

# include "pin_manager.hpp"
# include "tmp_config.hpp"

void
(set_digit_pin_mode (uint8_t (__digit_pid ), uint8_t (__digit_pmode ) ) ) { }

int unsigned inner_call_count = 0;
uint8_t output_buffer[8][8];
int unsigned set_call_count = 0;
bool o_buffer_finished = false;

void
(set_digit_pin_state (uint8_t (__digit_pid ), uint8_t (__digit_pstate ) ) )
{
    if (__digit_pid == 4 || __digit_pid == 5)
    {
        if (set_call_count == 8)
        {
            if (inner_call_count == 7)
            {
                o_buffer_finished = true;
                inner_call_count = 0;
            }
            else inner_call_count ++;

            set_call_count = 0;
        }

        output_buffer[inner_call_count][set_call_count] = __digit_pstate;
        set_call_count ++;
    }

    if (__digit_pid == 9 && __digit_pstate == 0x1)
    {
        std::cout << "SCC: " << set_call_count << ", ICC: " << inner_call_count << std::endl;
        for (int unsigned y = 0; y != 8; y ++)
        {
            std::cout << "OBITSET( ID: " << y << " ): ";
            for (int unsigned x = 0; x != 8; x ++)
            {
                std::cout << unsigned(output_buffer[y][x]);
            }
            std::cout << std::endl;
        }
        o_buffer_finished = false;
    }
}

#include <chrono>
#include <ctime>
// NOTE: add somthing so i can check if a int is null
int unsigned long (get_high_res_clock (int unsigned(__time_format) ) )
{
    if (__time_format == (tmp_config::time_format::__nano_seconds) )
    {
        auto hrc_now = std::chrono::high_resolution_clock::now( );

        auto nano_seconds = std::chrono::duration_cast <std::chrono::nanoseconds> (hrc_now.time_since_epoch( ) ).count( );

        return(nano_seconds);
    }
    return 0;
}

int unsigned(simulated_pin_state_i [3] [8]) = {
    {0x1, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1}, {0x1, 0x1, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1}, {0x1, 0x1, 0x1, 0x0, 0x1, 0x1, 0x1, 0x1} } ;

int unsigned(simulated_pin_state_c [10]) = {0x1, 0x0, 0x1, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1} ;

int unsigned(simulated_return_i ) = 0;
int unsigned(current_pin_pos_i ) = 0;
int unsigned(current_arr_pos ) = 0;

int unsigned(simulated_return_c ) = 0;
int unsigned(current_pin_pos_c ) = 0;


int unsigned tttt [4] = {0x1, 0x0, 0x1, 0x0};
int unsigned xcc = 0;
int unsigned out = 0;

int
(get_digit_pin_state (uint8_t(__digit_pid ) ) )
{
    if (__digit_pid == 2 || __digit_pid == 3)
    {
        simulated_return_i = (simulated_pin_state_i [current_arr_pos] [current_pin_pos_i]);

        if (current_pin_pos_i == 7)
        {
            current_pin_pos_i = 0;
            if (current_arr_pos == 2)
                current_arr_pos = 0;
            else
                current_arr_pos ++;
        }
        else current_pin_pos_i ++;
        return simulated_return_i;
    }

    if (__digit_pid == 6 )
    {
        simulated_return_c = (simulated_pin_state_c [current_pin_pos_c]);
        if (current_pin_pos_c == 9)
            current_pin_pos_c = 0;
        else
            current_pin_pos_c ++;
        return simulated_return_c;
    }
    if (__digit_pid == 7 )
    {
        out = tttt[xcc];
        if (xcc == 3)
        {
            xcc = 0;
        } else xcc ++;

        return (out);
    }
    return(0);
}

int unsigned tcount = 0;
int unsigned ltime = 1;
int unsigned pos = 0;
uint8_t test[8][8] =
{
    {0, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 0},
};

int unsigned
(external_mlinit (tmp::io_service(* __io_service ) ) )
{
    std::cout << "This Project is Still Early Development and Many things Need Fixing. Sorry :(" << std::endl;
    return 1;
}

int unsigned
(external_mltick (tmp::io_service(* __io_service ) ) )
{

    std::cout << "SET_IO_BITSET" << std::endl;
    __io_service-> set_io_bitset(0, 1, test[pos], 1, 0);
    return 0;
    __io_service-> flip_io_bitset(0, 1);

    tcount = 0;
    if (pos == 7)
        pos = 0;
    else
        pos ++;
    for (int unsigned (iface ) = 0; iface != 1; iface ++) {
    for (int unsigned (x ) = 0; x != 8; x ++)
        std::cout << unsigned(* __io_service-> get_io_bitset(0, 0, 0, x));


    std::cout << "/I::BITSET\n" << std::endl;

    for (int unsigned (x ) = 0; x != 8; x ++)
        std::cout << unsigned(* __io_service-> get_io_bitset(0, 1, 0, x));

    std::cout << "/O::BITSET\n" << std::endl;

    for (int unsigned(x ) = 0; x != 8; x ++)
    {
        for (int unsigned(y ) = 0; y != 8; y ++)
            std::cout << unsigned(*__io_service-> dati_bitset_buff.get_from_dbuff(2, iface, x, y, false, false, false, true));

        if ((__io_service-> dati_bitset_buff).is_block_smarker(true, iface, x) == true)
            std::cout << " & SM: " << "USED";
        else
            std::cout << " & SM: " << "FREE";

        std::cout << " : : ";

        for (int unsigned(y ) = 0; y != 8; y ++)
            std::cout << unsigned(*__io_service-> dato_bitset_buff.get_from_dbuff(2, iface, x, y, false, false, false, true));

        if (__io_service-> dato_bitset_buff.is_block_smarker(true, iface, x) == true)
            std::cout << " & SM: " << "USED";
        else
            std::cout << " & SM: " << "FREE";

        if (__io_service -> o_bitset_buff_pos[0] == x)
        {
            std::cout << " : BPOS<>";
        }

        std::cout << std::endl;
    }}
    tcount++;

    return 1;
}

# include "shift_reg.hpp"
# include "port_manager.hpp"
# include "dynamic_array.hpp"
# include "dpacket_array.hpp"
# include "tmp_ip.hpp"
# include "socket_manager.hpp"
# include "cint_convert.hpp"
# include "pin_manager.hpp"


int
(main( ) )
{
    tmp::pin_manager __pin_manager(1/*iface count*/);
    tmp::shift_reg __shift_reg;

    (__pin_manager.set_max_digit_pid_range(22));
    (__pin_manager.set_min_digit_pid_range(2));

    __shift_reg.set_pmanager_cinst_ptr(&__pin_manager);
    __pin_manager.set_dato_pid(2, 1, 0);

    __shift_reg.add_shift_register(0/*mode*/, 2/*pid*/, 3/*lpid*/, 4/*cpid*/, 5/*rpid*/, 8/*reg size*/);

    __shift_reg.bind_shift_register(2);


    std::cout << __shift_reg.is_shift_reg_binded(true, 2) << std::endl;



/*
    tmp::io_service __io_service;
    __io_service.service_init
    (
        & set_digit_pin_mode,
        & set_digit_pin_state,
        & get_digit_pin_state,
        & get_high_res_clock,
        & external_mlinit,
        & external_mltick
    );
*/
}

# endif /*ARDUINO*/

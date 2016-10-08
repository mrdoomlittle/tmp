# ifndef __shift__reg__hpp__
# define __shift__reg__hpp__

# define shift_reg_reset_pid 0
# define shift_reg_clock_pid 0
# define shift_reg_latch_pid 0

# define sreg_ctiming_holdup 0

# define def_max_amount_of_sreg 4

# ifdef ARDUINO
    # include <stdint.h>
# else
    # include <boost/cstdint.hpp>
# endif
# include <iostream>
# include "dynamic_array.hpp"
# include "pin_manager.hpp"
# include "tmp_config.hpp"
# include "bitset_list.hpp"

/* Created and Designed by MrDoomLittle
* Github URL: https://github.com/mrdoomlittle
* Email Addr: doctordoomlittle@gmail.com
* For Current Infomation about This Project
* See the File Called: ( INFOMATION )
*/
// still working on this
namespace tmp { class shift_reg
{
    protected :
        typedef pin_manager pmanager_ct;
        pmanager_ct
            (* pmanager_cinst_ptr) = nullptr;
    public :
        void
        (set_pmanager_cinst_ptr(pmanager_ct(* __pmanager_cinst_ptr)));
    protected :
        pmanager_ct
        (* get_pmanager_cinst_ptr());

    private :
        bool (is_pmanager_cinst_ptr_set) = false;

        int unsigned(shift_reg_ctohigh_holdup) = 100;
        int unsigned(shift_reg_ctolow_holdup) = 100;

        int unsigned(shift_reg_ltolow_holdup) = 100;

        int unsigned (max_amount_of_sreg ) = def_max_amount_of_sreg;


        void
        (set_shift_reg_opstate(int unsigned(__shift_reg_arr_pos), int unsigned(__shift_reg_opstate)))
        {

        }

        void
        (set_shift_reg_lpstate(int unsigned(__shift_reg_arr_pos), int unsigned(__shift_reg_lpstate)))
        {

        }

        void
        (set_shift_reg_cpstate(int unsigned(__shift_reg_arr_pos), int unsigned(__shift_reg_cpstate)))
        {

        }

        void
        (set_shift_reg_rpstate(int unsigned(__shift_reg_arr_pos), int unsigned(__shift_reg_rpstate)))
        {

        }
    public :
        void
        (set_shift_reg_oipstate(int unsigned(__shift_reg_arr_pos), int unsigned(__shift_reg_arr_ipos_id), int unsigned(__shift_reg_oipstate)))
        {

        }

        void
        (update_shift_reg_ipstates(int unsigned(__shift_reg_arr_pos)));

        void(set_shift_reg_pid())
        {

        }

        void(get_shift_ref_pid())
        {

        }

        void
        (set_shift_reg_obitset(int unsigned(* __obitset), int unsigned(__shift_reg_arr_pos)));

        int unsigned
        (* get_shift_reg_obitset(int unsigned(__shift_reg_arr_pos)));

        // hear we will mark if its a shift out or shift in register
        void
        (set_shift_reg_type());
        void
        (get_shift_reg_type());

        // we will add a shift reg hear but it wont do anything untill we bind it to the pin
        void
        (add_shift_register(int unsigned(__register_io_t), uint8_t(__shift_reg_pid), uint8_t(__shift_reg_lpid),
            uint8_t(__shift_reg_cpid), uint8_t(__shift_reg_rpid), int unsigned(__shift_reg_ipcount)));

        void
        (bind_shift_register(int unsigned(__register_io_t), int8_t(__shift_reg_pid)));

        bool
        (is_pid_being_used(uint8_t(__digit_pid)));

        void(del_shift_register());

        void
        (set_shift_reg_opstate());// input
        void
        (set_shift_reg_lpstate());// latch
        void
        (set_shift_reg_cpstate());// clock
        void
        (set_shift_reg_rpstate());// reset

        void
        (get_shift_ref_opstate());

        shift_reg();
        ~shift_reg();

    private :
        int unsigned(shift_reg_arr_pos ) = 0;

        dynamic_array <uint8_t> shift_reg_pid_list;

        // turn into array
        bitset_list <int unsigned> shift_reg_ibitset;
        bitset_list <int unsigned> shift_reg_obitset;

        dynamic_array <int unsigned> shift_reg_io_type;

        dynamic_array <int unsigned> shift_reg_ipcount_l;
        dynamic_array <int unsigned> shift_ref_ipstate_l;
} ; }

# endif /*__shift__reg__hpp__*/

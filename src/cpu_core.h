#ifndef CPU_CORE_H
#define CPU_CORE_H
/*
gamboop - an open source Game Boy Emulator
Copyright (C) 2017  Isaac Snellgrove

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, write snellgrove.isaac@gmail.com .

*/
#include <iostream>

using u8 = unsigned char;
using u16 = unsigned short;
using s8 = signed char;

class Cpu{
public:
    Cpu(){
        std::cout << "CPU created\n";
    };

    void tick(){op_table[pc];}//interperet one instruction
    void reset();

private:
    
    //registers

    //program counter and stack pointer
    u16 pc, sp;


    static void nop_(){}
    void ld_bc_d16(){}
    void ld_0xbc_a(){}
    void inc_bc(){}
    

    //opcode will be used as an index for an array of function pointers
    void (*op_table[256])(void) = {
        nop_
        //etc etc etc
    };


    
    //execute opcode
    //opcode helper functions////////////////////////////////
    
    //8 bit loads
    inline void ld_nn_n(u8 * nn);
    inline void ld_r1_r2(u8 * r1, u8 * r2);
    inline void ld_r1_r2_hl(u8 * r1, u8 * r2);
    inline void ld_r1_r2_hl_n(u8 * r1, u8 * r2);
    inline void ld_a_n(u8 * n);
    inline void ld_a_n_addr(u8 * n);
    inline void ld_a_n_imm();
    inline void ld_a_n_addr_nn();
    inline void ld_n_a(u16 * n);
    inline void ld_n_a_addr(u16 n);
    inline void ld_n_a_addr_nn();
    inline void ld_a_c();
    inline void ld_c_a();
    inline void ldd_a_hl();
    inline void ldd_hl_a();
    inline void ldi_a_hl();
    inline void ldi_hl_a();
    inline void ldh_n_a();
    inline void ldh_a_n();
    
    //16 bit loads
    inline void ld_n_nn(u16 * n);
    inline void ld_sp_hl();
    inline void ld_hl_sp_n();
    inline void ld_nn_sp();
    inline void push_nn(u16 nn);
    inline void pop_nn(u16 * nn);
    
    //8 bit ALU
    inline void add_a_n(u8 n);
    inline void add_a_addr();
    inline void add_a_imm();
    inline void adc_a_n(u8 n);
    inline void adc_a_addr();
    inline void adc_a_imm();
    inline void sub_a_n(u8 n);
    inline void sub_a_addr();
    inline void sub_a_imm();
    inline void sbc_a_n(u8 n);
    inline void sbc_a_addr();
    inline void sbc_a_imm();
    inline void and_n(u8 n);
    inline void and_addr();
    inline void and_imm();
    inline void or_n(u8 n);
    inline void or_addr();
    inline void or_imm();
    inline void xor_n(u8 n);
    inline void xor_addr();
    inline void xor_imm();
    inline void cp_n(u8 n);
    inline void cp_addr();
    inline void cp_imm( );
    inline void inc_n(u8 * n);
    inline void inc_addr();
    inline void dec_n(u8 * n);
    inline void dec_addr();
    
    //16 bit arithmetic
    inline void add_hl_n(u16 n);
    inline void add_sp_n(u16 n);
    inline void inc_nn(u16 * nn);
    inline void dec_nn(u16 * nn);
    
    //misc
    inline void swap_n(u8 * n);
    inline void swap_addr();
    inline void daa();
    inline void cpl();
    inline void ccf();
    inline void scf();
    inline void nop();
    inline void halt();
    inline void stop();
    inline void di();
    inline void ei();
    
    //rotates and shifts
    inline void rlca();
    inline void rla();
    inline void rrca();
    inline void rra();
    inline void rlc_n(u8 * n);
    inline void rlc_addr();
    inline void rl_n(u8 * n);
    inline void rl_addr();
    inline void rrc_n(u8 * n);
    inline void rrc_addr();
    inline void rr_n(u8 * n);
    inline void rr_addr();
    inline void sla_n(u8 * n);
    inline void sla_addr();
    inline void sra_n(u8 * n);
    inline void sra_addr();
    inline void srl_n(u8 * n);
    inline void srl_addr();
    
    //bit opcodes
    inline void bit_b_r(u8 b, u8 * n);
    inline void set_b_r(u8 b, u8 * n);
    inline void res_b_r(u8 b, u8 * n);
    
    //jumps
    inline void jp_nn();
    inline void jp_cc_nn();
    inline void jp_hl();
    inline void jr_n();
    inline void jr_cc_n();
    
    //calls
    inline void call_nn();
    inline void call_cc_nn();
    
    //restarts
    inline void rst_n(u8 n);
    
    //returns
    inline void ret();
    inline void ret_cc();
    inline void reti();
    
    
    
    //flag ops
    inline void set_c_flag();
    inline void set_h_flag();
    inline void set_s_flag();
    inline void set_z_flag();
        
    inline void reset_c_flag();
    inline void reset_h_flag();
    inline void reset_s_flag();
    inline void reset_z_flag();
    
    bool test_c_flag();
    bool test_h_flag();
    bool test_s_flag();
    bool test_z_flag();
        


};
#endif
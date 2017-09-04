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
    
    //registers - same method as Cinoop, credit given to cturt
	struct reg{
                struct {
                    union {
                        struct {
                            unsigned char f;
                            unsigned char a;
                        };
                        unsigned short af;
                    };
                };
                
                struct {
                    union {
                        struct {
                            unsigned char c;
                            unsigned char b;
                        };
                        unsigned short bc;
                    };
                };
                
                struct {
                    union {
                        struct {
                            unsigned char e;
                            unsigned char d;
                        };
                        unsigned short de;
                    };
                };
                
                struct {
                    union {
                        struct {
                            unsigned char l;
                            unsigned char h;
                        };
                        unsigned short hl;
                    };
                };
            };

    //program counter and stack pointer
    u16 pc, sp;

    //0x00 to 0x0f
    static void nop_(){}
    static void ld_bc_d16(){}
    static void ld_0xbc_a(){}
    static void inc_bc(){}
    static void inc_b(){}
    static void dec_b(){}
    static void ld_b_d8(){}
    static void rlca_(){}
    static void ld_0xa16_sp(){}
    static void add_hl_bc(){}
    static void ld_a_0xbc(){}
    static void dec_bc(){}
    static void inc_c(){}
    static void dec_c(){}
    static void ld_c_d8(){}
    static void rrca_(){}

    //0x10 to 0x1f
    static void stop_(){}
    static void ld_de_d16(){}
    static void ld_0xde_a(){}
    static void inc_de(){}
    static void inc_d(){}
    static void dec_d(){}
    static void ld_d_d8(){}
    static void rla_(){}
    static void jr_r8(){}
    static void add_hl_de(){}
    static void ld_a_0xde(){}
    static void dec_de(){}
    static void inc_e(){}
    static void dec_e(){}
    static void ld_e_d8(){}
    static void rra_(){}

    //0x20 to 0x2f
    static void jr_nz_r8(){}
    static void ld_hl_d16(){}
    static void ld_0xhli_a(){}
    static void inc_hl(){}
    static void inc_h(){}
    static void dec_h(){}
    static void ld_h_d8(){}
    static void daa_(){}
    static void jr_z_r8(){}
    static void add_hl_hl(){}
    static void ld_a_0xhli(){}
    static void dec_hl(){}
    static void inc_l(){}
    static void dec_l(){}
    static void ld_l_d8(){}
    static void cpl_(){}

    //0x30 to 0x3f
    static void jr_nc_r8(){}
    static void ld_sp_d16(){}
    static void ld_0xhld_a(){}
    static void inc_sp(){}
    static void inc_0xhl(){}
    static void dec_0xhl(){}
    static void ld_0xhl_d8(){}
    static void scf_(){}
    static void jr_c_r8(){}
    static void add_hl_sp(){}
    static void ld_a_0xhld(){}
    static void dec_sp(){}
    static void inc_a(){}
    static void dec_a(){}
    static void ld_a_d8(){}
    static void ccf_(){}

    //0x40 to 0x4f
    static void ld_b_b(){}                
    static void ld_b_c(){}                
    static void ld_b_d(){}                
    static void ld_b_e(){}                
    static void ld_b_h(){}                
    static void ld_b_l(){}                
    static void ld_b_0xhl(){}                
    static void ld_b_a(){}                
    static void ld_c_b(){}                
    static void ld_c_c(){}                
    static void ld_c_d(){}                
    static void ld_c_e(){}                
    static void ld_c_h(){}                
    static void ld_c_l(){}                
    static void ld_c_0xhl(){}                
    static void ld_c_a_(){}                
    
   //0x50 to 0x5f
   static void ld_d_b(){}                
   static void ld_d_c(){}                
   static void ld_d_d(){}                
   static void ld_d_e(){}                
   static void ld_d_h(){}                
   static void ld_d_l(){}                
   static void ld_d_0xhl(){}                
   static void ld_d_a(){}                
   static void ld_e_b(){}                
   static void ld_e_c(){}                
   static void ld_e_d(){}                
   static void ld_e_e(){}                
   static void ld_e_h(){}                
   static void ld_e_l(){}                
   static void ld_e_0xhl(){}                
   static void ld_e_a(){}                
    
   //0x60 to 0x6f
   static void ld_h_b(){}                
   static void ld_h_c(){}                
   static void ld_h_d(){}                
   static void ld_h_e(){}                
   static void ld_h_h(){}                
   static void ld_h_l(){}                
   static void ld_h_0xhl(){}                
   static void ld_h_a(){}                
   static void ld_l_b(){}                
   static void ld_l_c(){}                
   static void ld_l_d(){}                
   static void ld_l_e(){}                
   static void ld_l_h(){}                
   static void ld_l_l(){}                
   static void ld_l_0xhl(){}                
   static void ld_l_a(){}                

   //0x70 to 0x7f
   static void ld_0xhl_b(){}                
   static void ld_0xhl_c(){}                
   static void ld_0xhl_d(){}                
   static void ld_0xhl_e(){}                
   static void ld_0xhl_h(){}                
   static void ld_0xhl_l(){}                
   static void halt_(){}                
   static void ld_0xhl_a(){}                
   static void ld_a_b(){}                
   static void ld_a_c_(){}                
   static void ld_a_d(){}                
   static void ld_a_e(){}                
   static void ld_a_h(){}                
   static void ld_a_l(){}                
   static void ld_a_0xhl(){}                
   static void ld_a_a(){}                

    //opcode will be used as an index for an array of function pointers
    void (*op_table[256])(void) = {
        nop_, ld_bc_d16
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
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
                            u8 f;
                            u8 a;
                        };
                        u16 af;
                    };
                };
                
                struct {
                    union {
                        struct {
                            u8 c;
                            u8 b;
                        };
                        u16 bc;
                    };
                };
                
                struct {
                    union {
                        struct {
                            u8 e;
                            u8 d;
                        };
                        u16 de;
                    };
                };
                
                struct {
                    union {
                        struct {
                            u8 l;
                            u8 h;
                        };
                        u16 hl;
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

   //0x80 to 0x8f
   static void add_a_b(){}
   static void add_a_c(){}
   static void add_a_d(){}
   static void add_a_e(){}
   static void add_a_h(){}
   static void add_a_l(){}
   static void add_a_0xhl(){}
   static void add_a_a(){}
   static void adc_a_b(){}
   static void adc_a_c(){}
   static void adc_a_d(){}
   static void adc_a_e(){}
   static void adc_a_h(){}
   static void adc_a_l(){}
   static void adc_a_0xhl(){}
   static void adc_a_a(){}

   //0x90 to 0x9f
   static void sub_b(){}
   static void sub_c(){}
   static void sub_d(){}
   static void sub_e(){}
   static void sub_h(){}
   static void sub_l(){}
   static void sub_0xhl(){}
   static void sub_a(){}
   static void sbc_b(){}
   static void sbc_c(){}
   static void sbc_d(){}
   static void sbc_e(){}
   static void sbc_h(){}
   static void sbc_l(){}
   static void sbc_0xhl(){}
   static void sbc_a(){}

   //0xa0 to 0xaf
   static void and_b(){}
   static void and_c(){}
   static void and_d(){}
   static void and_e(){}
   static void and_h(){}
   static void and_l(){}
   static void and_0xhl(){}
   static void and_a(){}
   static void xor_b(){}
   static void xor_c(){}
   static void xor_d(){}
   static void xor_e(){}
   static void xor_h(){}
   static void xor_l(){}
   static void xor_0xhl(){}
   static void xor_a(){}

   //0xb0 to 0xbf
   static void or_b(){}
   static void or_c(){}
   static void or_d(){}
   static void or_e(){}
   static void or_h(){}
   static void or_l(){}
   static void or_0xhl(){}
   static void or_a(){}
   static void cp_b(){}
   static void cp_c(){}
   static void cp_d(){}
   static void cp_e(){}
   static void cp_h(){}
   static void cp_l(){}
   static void cp_0xhl(){}
   static void cp_a(){}

   //0xc0 to 0xcf
   static void ret_nz(){}
   static void pop_bc(){}
   static void jp_nz_a16(){}
   static void jp_a16(){}
   static void call_nz_a16(){}
   static void push_bc(){}
   static void add_a_d8(){}
   static void rst_00h(){}
   static void ret_z(){}
   static void ret_(){}
   static void jp_z_a16(){}
   static void prefix_cb(){}
   static void call_z_a16_(){}
   static void call_a16(){}
   static void adc_a_d8(){}
   static void rst_08h(){}

   //0xd0 to 0xdf
   static void ret_nc(){}
   static void pop_de(){}
   static void jp_nc_a16(){}
   static void illegal_0xd3(){}
   static void call_nc_a16(){}
   static void push_de(){}
   static void sub_d8(){}
   static void rst_10h(){}
   static void ret_c(){}
   static void reti_(){}
   static void jp_c_a16(){}
   static void illegal_0xdb(){}
   static void call_c_a16_(){}
   static void illegal_0xdd(){}
   static void sbc_a_d8(){}
   static void rst_18h(){}

   //0xe0 to 0xef
   static void ldh_0xa8_a(){}
   static void pop_hl(){}
   static void ld_0xc_a(){}
   static void illegal_0xe3(){}
   static void illegal_0xe4(){}
   static void push_hl(){}
   static void and_d8(){}
   static void rst_20h(){}
   static void add_sp_r8(){}
   static void jp_0xhl(){}
   static void ld_0xa16_a(){}
   static void illegal_0xeb(){}
   static void illegal_0xec(){}
   static void illegal_0xed(){}
   static void xor_d8(){}
   static void rst_28h(){}

    //0xf0 to 0xff
    static void ldh_a_0xa8(){}
    static void pop_af(){}
    static void ld_a_0xc(){}
    static void di_(){}
    static void illegal_0xf4(){}
    static void push_af(){}
    static void or_d8(){}
    static void rst_30h(){}
    static void ld_hl_sp_r8(){}
    static void ld_sp_hl_(){}
    static void ld_a_0xa16(){}
    static void ei_(){}
    static void illegal_0xfc(){}
    static void illegal_0xfd(){}
    static void cp_d8(){}
    static void rst_38h(){}




   //opcode will be used as an index for an array of function pointers
    void (*op_table[256])(void) = {
    //0x00 to 0x0f
     nop_,
     ld_bc_d16,
     ld_0xbc_a,
     inc_bc,
     inc_b,
     dec_b,
     ld_b_d8,
     rlca_,
     ld_0xa16_sp,
     add_hl_bc,
     ld_a_0xbc,
     dec_bc,
     inc_c,
     dec_c,
     ld_c_d8,
     rrca_,

    //0x10 to 0x1f
     stop_,
     ld_de_d16,
     ld_0xde_a,
     inc_de,
     inc_d,
     dec_d,
     ld_d_d8,
     rla_,
     jr_r8,
     add_hl_de,
     ld_a_0xde,
     dec_de,
     inc_e,
     dec_e,
     ld_e_d8,
     rra_,

    //0x20 to 0x2f
     jr_nz_r8,
     ld_hl_d16,
     ld_0xhli_a,
     inc_hl,
     inc_h,
     dec_h,
     ld_h_d8,
     daa_,
     jr_z_r8,
     add_hl_hl,
     ld_a_0xhli,
     dec_hl,
     inc_l,
     dec_l,
     ld_l_d8,
     cpl_,

    //0x30 to 0x3f
     jr_nc_r8,
     ld_sp_d16,
     ld_0xhld_a,
     inc_sp,
     inc_0xhl,
     dec_0xhl,
     ld_0xhl_d8,
     scf_,
     jr_c_r8,
     add_hl_sp,
     ld_a_0xhld,
     dec_sp,
     inc_a,
     dec_a,
     ld_a_d8,
     ccf_,

    //0x40 to 0x4f
     ld_b_b,                
     ld_b_c,               
     ld_b_d,              
     ld_b_e,                
     ld_b_h,               
     ld_b_l,                
     ld_b_0xhl,                
     ld_b_a,                
     ld_c_b,                
     ld_c_c,                
     ld_c_d,                
     ld_c_e,                
     ld_c_h,                
     ld_c_l,                
     ld_c_0xhl,                
     ld_c_a_,                
    
   //0x50 to 0x5f
    ld_d_b,                
    ld_d_c,                
    ld_d_d,                
    ld_d_e,                
    ld_d_h,                
    ld_d_l,                
    ld_d_0xhl,                
    ld_d_a,                
    ld_e_b,                
    ld_e_c,                
    ld_e_d,                
    ld_e_e,                
    ld_e_h,                
    ld_e_l,                
    ld_e_0xhl,                
    ld_e_a,             
    
   //0x60 to 0x6f
    ld_h_b,                
    ld_h_c,                
    ld_h_d,                
    ld_h_e,                
    ld_h_h,                
    ld_h_l,                
    ld_h_0xhl,                
    ld_h_a,             
    ld_l_b,               
    ld_l_c,                
    ld_l_d,                
    ld_l_e,                
    ld_l_h,                
    ld_l_l,                
    ld_l_0xhl,                
    ld_l_a,             

   //0x70 to 0x7f
    ld_0xhl_b,                
    ld_0xhl_c,                
    ld_0xhl_d,                
    ld_0xhl_e,                
    ld_0xhl_h,                
    ld_0xhl_l,                
    halt_,               
    ld_0xhl_a,                
    ld_a_b,               
    ld_a_c_,                
    ld_a_d,                
    ld_a_e,                
    ld_a_h,                
    ld_a_l,                
    ld_a_0xhl,                
    ld_a_a,                

   //0x80 to 0x8f
    add_a_b,
    add_a_c,
    add_a_d,
    add_a_e,
    add_a_h,
    add_a_l,
    add_a_0xhl,
    add_a_a,
    adc_a_b,
    adc_a_c,
    adc_a_d,
    adc_a_e,
    adc_a_h,
    adc_a_l,
    adc_a_0xhl,
    adc_a_a,

   //0x90 to 0x9f
    sub_b,
    sub_c,
    sub_d,
    sub_e,
    sub_h,
    sub_l,
    sub_0xhl,
    sub_a,
    sbc_b,
    sbc_c,
    sbc_d,
    sbc_e,
    sbc_h,
    sbc_l,
    sbc_0xhl,
    sbc_a,

   //0xa0 to 0xaf
    and_b,
    and_c,
    and_d,
    and_e,
    and_h,
    and_l,
    and_0xhl,
    and_a,
    xor_b,
    xor_c,
    xor_d,
    xor_e,
    xor_h,
    xor_l,
    xor_0xhl,
    xor_a,

   //0xb0 to 0xbf
    or_b,
    or_c,
    or_d,
    or_e,
    or_h,
    or_l,
    or_0xhl,
    or_a,
    cp_b,
    cp_c,
    cp_d,
    cp_e,
    cp_h,
    cp_l,
    cp_0xhl,
    cp_a,

   //0xc0 to 0xcf
    ret_nz,
    pop_bc,
    jp_nz_a16,
    jp_a16,
    call_nz_a16,
    push_bc,
    add_a_d8,
    rst_00h,
    ret_z,
    ret_,
    jp_z_a16,
    prefix_cb,
    call_z_a16_,
    call_a16,
    adc_a_d8,
    rst_08h,

   //0xd0 to 0xdf
    ret_nc,
    pop_de,
    jp_nc_a16,
    illegal_0xd3,
    call_nc_a16,
    push_de,
    sub_d8,
    rst_10h,
    ret_c,
    reti_,
    jp_c_a16,
    illegal_0xdb,
    call_c_a16_,
    illegal_0xdd,
    sbc_a_d8,
    rst_18h,

   //0xe0 to 0xef
    ldh_0xa8_a,
    pop_hl,
    ld_0xc_a,
    illegal_0xe3,
    illegal_0xe4,
    push_hl,
    and_d8,
    rst_20h,
    add_sp_r8,
    jp_0xhl,
    ld_0xa16_a,
    illegal_0xeb,
    illegal_0xec,
    illegal_0xed,
    xor_d8,
    rst_28h,

    //0xf0 to 0xff
     ldh_a_0xa8,
     pop_af,
     ld_a_0xc,
     di_,
     illegal_0xf4,
     push_af,
     or_d8,
     rst_30h,
     ld_hl_sp_r8,
     ld_sp_hl_,
     ld_a_0xa16,
     ei_,
     illegal_0xfc,
     illegal_0xfd,
     cp_d8,
     rst_38h,

    };


    //cb opcodes

    //0x00 to 0x0f
    static void rlc_b(){}
    static void rlc_c(){}
    static void rlc_d(){}
    static void rlc_e(){}
    static void rlc_h(){}
    static void rlc_l(){}
    static void rlc_0xhl(){}
    static void rlc_a(){}
    static void rrc_b(){}
    static void rrc_c(){}
    static void rrc_d(){}
    static void rrc_e(){}
    static void rrc_h(){}
    static void rrc_l(){}
    static void rrc_0xhl(){}
    static void rrc_a(){}

    //0x10 to 0x1f
    static void rl_b(){}
    static void rl_c(){}
    static void rl_d(){}
    static void rl_e(){}
    static void rl_h(){}
    static void rl_l(){}
    static void rl_0xhl(){}
    static void rl_a(){}
    static void rr_b(){}
    static void rr_c(){}
    static void rr_d(){}
    static void rr_e(){}
    static void rr_h(){}
    static void rr_l(){}
    static void rr_0xhl(){}
    static void rr_a(){}

    //0x20 to 0x2f
    static void sla_b(){}
    static void sla_c(){}
    static void sla_d(){}
    static void sla_e(){}
    static void sla_h(){}
    static void sla_l(){}
    static void sla_0xhl(){}
    static void sla_a(){}
    static void sra_b(){}
    static void sra_c(){}
    static void sra_d(){}
    static void sra_e(){}
    static void sra_h(){}
    static void sra_l(){}
    static void sra_0xhl(){}
    static void sra_a(){}

    //0x30 to 0x3f
    static void swap_b(){}
    static void swap_c(){}
    static void swap_d(){}
    static void swap_e(){}
    static void swap_h(){}
    static void swap_l(){}
    static void swap_0xhl(){}
    static void swap_a(){}
    static void srl_b(){}
    static void srl_c(){}
    static void srl_d(){}
    static void srl_e(){}
    static void srl_h(){}
    static void srl_l(){}
    static void srl_0xhl(){}
    static void srl_a(){}

    //0x40 to 0x4f
    static void bit_0_b(){}
    static void bit_0_c(){}
    static void bit_0_d(){}
    static void bit_0_e(){}
    static void bit_0_h(){}
    static void bit_0_l(){}
    static void bit_0_0xhl(){}
    static void bit_0_a(){}
    static void bit_1_b(){}
    static void bit_1_c(){}
    static void bit_1_d(){}
    static void bit_1_e(){}
    static void bit_1_h(){}
    static void bit_1_l(){}
    static void bit_1_0xhl(){}
    static void bit_1_a(){}

    //0x50 to 0x5f
    static void bit_2_b(){}
    static void bit_2_c(){}
    static void bit_2_d(){}
    static void bit_2_e(){}
    static void bit_2_h(){}
    static void bit_2_l(){}
    static void bit_2_0xhl(){}
    static void bit_2_a(){}
    static void bit_3_b(){}
    static void bit_3_c(){}
    static void bit_3_d(){}
    static void bit_3_e(){}
    static void bit_3_h(){}
    static void bit_3_l(){}
    static void bit_3_0xhl(){}
    static void bit_3_a(){}
    
    //0x60 to 0x6f   
    static void bit_4_b(){}
    static void bit_4_c(){}
    static void bit_4_d(){}
    static void bit_4_e(){}
    static void bit_4_h(){}
    static void bit_4_l(){}
    static void bit_4_0xhl(){}
    static void bit_4_a(){}
    static void bit_5_b(){}
    static void bit_5_c(){}
    static void bit_5_d(){}
    static void bit_5_e(){}
    static void bit_5_h(){}
    static void bit_5_l(){}
    static void bit_5_0xhl(){}
    static void bit_5_a(){}
    
    //0x70 to 0x7f
    static void bit_6_b(){}
    static void bit_6_c(){}
    static void bit_6_d(){}
    static void bit_6_e(){}
    static void bit_6_h(){}
    static void bit_6_l(){}
    static void bit_6_0xhl(){}
    static void bit_6_a(){}
    static void bit_7_b(){}
    static void bit_7_c(){}
    static void bit_7_d(){}
    static void bit_7_e(){}
    static void bit_7_h(){}
    static void bit_7_l(){}
    static void bit_7_0xhl(){}
    static void bit_7_a(){}
    
    //0x80 to 0x8f
    static void res_0_b(){}
    static void res_0_c(){}
    static void res_0_d(){}
    static void res_0_e(){}
    static void res_0_h(){}
    static void res_0_l(){}
    static void res_0_0xhl(){}
    static void res_0_a(){}
    static void res_1_b(){}
    static void res_1_c(){}
    static void res_1_d(){}
    static void res_1_e(){}
    static void res_1_h(){}
    static void res_1_l(){}
    static void res_1_0xhl(){}
    static void res_1_a(){}

    //0x90 to 0x9f
    static void res_2_b(){}
    static void res_2_c(){}
    static void res_2_d(){}
    static void res_2_e(){}
    static void res_2_h(){}
    static void res_2_l(){}
    static void res_2_0xhl(){}
    static void res_2_a(){}
    static void res_3_b(){}
    static void res_3_c(){}
    static void res_3_d(){}
    static void res_3_e(){}
    static void res_3_h(){}
    static void res_3_l(){}
    static void res_3_0xhl(){}
    static void res_3_a(){}

    //0xa0 to 0xaf
    static void res_4_b(){}
    static void res_4_c(){}
    static void res_4_d(){}
    static void res_4_e(){}
    static void res_4_h(){}
    static void res_4_l(){}
    static void res_4_0xhl(){}
    static void res_4_a(){}
    static void res_5_b(){}
    static void res_5_c(){}
    static void res_5_d(){}
    static void res_5_e(){}
    static void res_5_h(){}
    static void res_5_l(){}
    static void res_5_0xhl(){}
    static void res_5_a(){}

    //0xb0 to 0xbf
    static void res_6_b(){}
    static void res_6_c(){}
    static void res_6_d(){}
    static void res_6_e(){}
    static void res_6_h(){}
    static void res_6_l(){}
    static void res_6_0xhl(){}
    static void res_6_a(){}
    static void res_7_b(){}
    static void res_7_c(){}
    static void res_7_d(){}
    static void res_7_e(){}
    static void res_7_h(){}
    static void res_7_l(){}
    static void res_7_0xhl(){}
    static void res_7_a(){}

    //0xc0 to 0xcf
    static void set_0_b(){}
    static void set_0_c(){}
    static void set_0_d(){}
    static void set_0_e(){}
    static void set_0_h(){}
    static void set_0_l(){}
    static void set_0_0xhl(){}
    static void set_0_a(){}
    static void set_1_b(){}
    static void set_1_c(){}
    static void set_1_d(){}
    static void set_1_e(){}
    static void set_1_h(){}
    static void set_1_l(){}
    static void set_1_0xhl(){}
    static void set_1_a(){}

    //0xd0 to 0xdf
    static void set_2_b(){}
    static void set_2_c(){}
    static void set_2_d(){}
    static void set_2_e(){}
    static void set_2_h(){}
    static void set_2_l(){}
    static void set_2_0xhl(){}
    static void set_2_a(){}
    static void set_3_b(){}
    static void set_3_c(){}
    static void set_3_d(){}
    static void set_3_e(){}
    static void set_3_h(){}
    static void set_3_l(){}
    static void set_3_0xhl(){}
    static void set_3_a(){}

    //0xe0 to 0xef
    static void set_4_b(){}
    static void set_4_c(){}
    static void set_4_d(){}
    static void set_4_e(){}
    static void set_4_h(){}
    static void set_4_l(){}
    static void set_4_0xhl(){}
    static void set_4_a(){}
    static void set_5_b(){}
    static void set_5_c(){}
    static void set_5_d(){}
    static void set_5_e(){}
    static void set_5_h(){}
    static void set_5_l(){}
    static void set_5_0xhl(){}
    static void set_5_a(){}

    //0xf0 to 0xff
    static void set_6_b(){}
    static void set_6_c(){}
    static void set_6_d(){}
    static void set_6_e(){}
    static void set_6_h(){}
    static void set_6_l(){}
    static void set_6_0xhl(){}
    static void set_6_a(){}
    static void set_7_b(){}
    static void set_7_c(){}
    static void set_7_d(){}
    static void set_7_e(){}
    static void set_7_h(){}
    static void set_7_l(){}
    static void set_7_0xhl(){}
    static void set_7_a(){}

    void (*cb_op_table[256])(void) = {
   //0x00 to 0x0f
    rlc_b,
    rlc_c,
    rlc_d,
    rlc_e,
    rlc_h,
    rlc_l,
    rlc_0xhl,
    rlc_a,
    rrc_b,
    rrc_c,
    rrc_d,
    rrc_e,
    rrc_h,
    rrc_l,
    rrc_0xhl,
    rrc_a,

   //0x10 to 0x1f
    rl_b,
    rl_c,
    rl_d,
    rl_e,
    rl_h,
    rl_l,
    rl_0xhl,
    rl_a,
    rr_b,
    rr_c,
    rr_d,
    rr_e,
    rr_h,
    rr_l,
    rr_0xhl,
    rr_a,

   //0x20 to 0x2f
    sla_b,
    sla_c,
    sla_d,
    sla_e,
    sla_h,
    sla_l,
    sla_0xhl,
    sla_a,
    sra_b,
    sra_c,
    sra_d,
    sra_e,
    sra_h,
    sra_l,
    sra_0xhl,
    sra_a,

   //0x30 to 0x3f
    swap_b,
    swap_c,
    swap_d,
    swap_e,
    swap_h,
    swap_l,
    swap_0xhl,
    swap_a,
    srl_b,
    srl_c,
    srl_d,
    srl_e,
    srl_h,
    srl_l,
    srl_0xhl,
    srl_a,

   //0x40 to 0x4f
    bit_0_b,
    bit_0_c,
    bit_0_d,
    bit_0_e,
    bit_0_h,
    bit_0_l,
    bit_0_0xhl,
    bit_0_a,
    bit_1_b,
    bit_1_c,
    bit_1_d,
    bit_1_e,
    bit_1_h,
    bit_1_l,
    bit_1_0xhl,
    bit_1_a,

   //0x50 to 0x5f
    bit_2_b,
    bit_2_c,
    bit_2_d,
    bit_2_e,
    bit_2_h,
    bit_2_l,
    bit_2_0xhl,
    bit_2_a,
    bit_3_b,
    bit_3_c,
    bit_3_d,
    bit_3_e,
    bit_3_h,
    bit_3_l,
    bit_3_0xhl,
    bit_3_a,
   
   //0x60 to 0x6f   
    bit_4_b,
    bit_4_c,
    bit_4_d,
    bit_4_e,
    bit_4_h,
    bit_4_l,
    bit_4_0xhl,
    bit_4_a,
    bit_5_b,
    bit_5_c,
    bit_5_d,
    bit_5_e,
    bit_5_h,
    bit_5_l,
    bit_5_0xhl,
    bit_5_a,
   
   //0x70 to 0x7f
    bit_6_b,
    bit_6_c,
    bit_6_d,
    bit_6_e,
    bit_6_h,
    bit_6_l,
    bit_6_0xhl,
    bit_6_a,
    bit_7_b,
    bit_7_c,
    bit_7_d,
    bit_7_e,
    bit_7_h,
    bit_7_l,
    bit_7_0xhl,
    bit_7_a,
   
   //0x80 to 0x8f
    res_0_b,
    res_0_c,
    res_0_d,
    res_0_e,
    res_0_h,
    res_0_l,
    res_0_0xhl,
    res_0_a,
    res_1_b,
    res_1_c,
    res_1_d,
    res_1_e,
    res_1_h,
    res_1_l,
    res_1_0xhl,
    res_1_a,

   //0x90 to 0x9f
    res_2_b,
    res_2_c,
    res_2_d,
    res_2_e,
    res_2_h,
    res_2_l,
    res_2_0xhl,
    res_2_a,
    res_3_b,
    res_3_c,
    res_3_d,
    res_3_e,
    res_3_h,
    res_3_l,
    res_3_0xhl,
    res_3_a,

   //0xa0 to 0xaf
    res_4_b,
    res_4_c,
    res_4_d,
    res_4_e,
    res_4_h,
    res_4_l,
    res_4_0xhl,
    res_4_a,
    res_5_b,
    res_5_c,
    res_5_d,
    res_5_e,
    res_5_h,
    res_5_l,
    res_5_0xhl,
    res_5_a,

   //0xb0 to 0xbf
    res_6_b,
    res_6_c,
    res_6_d,
    res_6_e,
    res_6_h,
    res_6_l,
    res_6_0xhl,
    res_6_a,
    res_7_b,
    res_7_c,
    res_7_d,
    res_7_e,
    res_7_h,
    res_7_l,
    res_7_0xhl,
    res_7_a,

   //0xc0 to 0xcf
    set_0_b,
    set_0_c,
    set_0_d,
    set_0_e,
    set_0_h,
    set_0_l,
    set_0_0xhl,
    set_0_a,
    set_1_b,
    set_1_c,
    set_1_d,
    set_1_e,
    set_1_h,
    set_1_l,
    set_1_0xhl,
    set_1_a,

   //0xd0 to 0xdf
    set_2_b,
    set_2_c,
    set_2_d,
    set_2_e,
    set_2_h,
    set_2_l,
    set_2_0xhl,
    set_2_a,
    set_3_b,
    set_3_c,
    set_3_d,
    set_3_e,
    set_3_h,
    set_3_l,
    set_3_0xhl,
    set_3_a,

   //0xe0 to 0xef
    set_4_b,    set_4_c,    set_4_d,    set_4_e,
    set_4_h,    set_4_l,    set_4_0xhl, set_4_a,
    set_5_b,    set_5_c,    set_5_d,    set_5_e,
    set_5_h,    set_5_l,    set_5_0xhl, set_5_a,

   //0xf0 to 0xff
    set_6_b,    set_6_c,    set_6_d,       set_6_e,    
    set_6_h,    set_6_l,    set_6_0xhl,    set_6_a, 
    set_7_b,    set_7_c,    set_7_d,       set_7_e,  
    set_7_h,    set_7_l,    set_7_0xhl,    set_7_a

    };

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
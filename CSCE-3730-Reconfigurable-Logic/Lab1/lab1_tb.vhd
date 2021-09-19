----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 09/22/2020 05:36:11 PM
-- Design Name: 
-- Module Name: lab1_tb - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity lab1_tb is
--  Port ( );
end lab1_tb;

architecture Behavioral of lab1_tb is

COMPONENT lab1 IS
PORT(
  A,B,C,D: IN BIT;
  F: OUT BIT
);
END COMPONENT;

--Inputs
signal input1 : bit:='0';
signal input2 : bit:='0';
signal input3 : bit:='0';
signal input4 : bit:='0';

--Outputs
signal output : bit;  

begin
uut: lab1 PORT MAP(A => input1, B => input2, C=> input3,
  D => input4,
  F => output);
  process
  begin
    wait for 10ms; --0001
    input4<= '1';
    wait for 10ms; --0010
    input3<='1'; input4 <='0'; 
    wait for 10ms; --0011
    input4<= '1'; 
    wait for 10ms; --0100
    input2<='1'; input3<='0'; input4 <='0'; 
    wait for 10ms; --0101
    input4<= '1'; 
    wait for 10ms; --0110
    input2<='1'; input3<='1'; input4 <='0'; 
    wait for 10ms; --0111
    input4<= '1'; 
    wait for 10ms; --1000
    input1<='1'; input2<='0'; input3<='0'; input4 <='0'; 
    wait for 10ms; --1001
    input4<='1';
    wait for 10ms; --1010
    input3<='1'; input4 <='0';
    wait for 10ms; --1011
    input4<='1';
    wait for 10ms; --1100
    input2<='1'; input3<='0'; input4 <='0';
    wait for 10ms; --1101
    input4<='1';
    wait for 10ms; --1110
    input2<='1'; input3<='1'; input4 <='0';
    wait for 10ms; --1111
    input4<='1';
    
    wait;
   end process; 

end Behavioral;

----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 10/05/2020 05:49:15 PM
-- Design Name: 
-- Module Name: decoder2to4_tb - Behavioral
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

entity lab2_tb is
--  Port ( );
end lab2_tb;

architecture Behavioral of lab2_tb is

COMPONENT decode4to16
  Port(     x : in STD_LOGIC_VECTOR (3 downto 0);
            en : in STD_LOGIC;
            y : out STD_LOGIC_VECTOR (15 downto 0));
end COMPONENT;

signal aa: std_logic_vector(3 downto 0) := (others => '0');
signal ens: std_logic;
signal bs: std_logic_vector(15 downto 0);
    
begin

uut: decode4to16 PORT MAP (
  x=>aa,
  y=>bs,
  en=>ens );
  
  process
  begin
  ens <='0';
  wait for 10ms;
   aa <= "0000";
  wait for 10ms;
   aa <= "0001";
  wait for 10ms;
   aa <= "0010";
  wait for 10ms;
   aa <= "0011";
  wait for 10ms;
   aa <= "0100";
  wait for 10ms;
   aa <= "0101";
  wait for 10ms;
   aa <= "0110";
  wait for 10ms;
   aa <= "0111";
  wait for 10ms;
   aa <= "1000";
  wait for 10ms;
   aa <= "1001";
  wait for 10ms;
   aa <= "1010";
  wait for 10ms;
   aa <= "1011";
  wait for 10ms;
   aa <= "1100";
  wait for 10ms;
   aa <= "1101";
  wait for 10ms;
   aa <= "1110";   
  wait for 10ms;
   aa <= "1111";
  wait for 10ms;

  ens <= '1';
  
   aa <= "0000";
  wait for 10ms;
   aa <= "0001";
  wait for 10ms;
   aa <= "0010";
  wait for 10ms;
   aa <= "0011";
  wait for 10ms;
   aa <= "0100";
  wait for 10ms;
   aa <= "0101";
  wait for 10ms;
   aa <= "0110";
  wait for 10ms;
   aa <= "0111";
  wait for 10ms;
   aa <= "1000";
  wait for 10ms;
   aa <= "1001";
  wait for 10ms;
   aa <= "1010";
  wait for 10ms;
   aa <= "1011";
  wait for 10ms;
   aa <= "1100";
  wait for 10ms;
   aa <= "1101";
  wait for 10ms;
   aa <= "1110";   
  wait for 10ms;
   aa <= "1111";
  wait;

end process;     

end Behavioral;

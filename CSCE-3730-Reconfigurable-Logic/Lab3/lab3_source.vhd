----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 10/19/2020 01:28:08 PM
-- Design Name: 
-- Module Name: lab_3source - Behavioral
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
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity lab_3source is
    Port ( clock: in STD_LOGIC;                               --system clock
           --res: in STD_LOGIC;                                 --synchronous reset
           a : in STD_LOGIC_VECTOR (3 downto 0);              --a input
           b : in STD_LOGIC_VECTOR (3 downto 0);              --b input
           alu_select: in STD_LOGIC_VECTOR(2 downto 0);       --logic unit opcode
           y : out STD_LOGIC_VECTOR (7 downto 0));            --output from logic unit
end lab_3source;

architecture Behavioral of lab_3source is
signal result: std_logic_vector (7 downto 0);
signal res: std_logic;
begin
    process(clock, a,b,alu_select) is
     begin
      if rising_edge(clock) then
         if res = '1' then
           y <= (others => '0');
         else   
           case(alu_select) is
             when "000" =>
               y <= std_logic_vector(to_unsigned((to_integer(unsigned(a)) + to_integer(unsigned(b))),8)); --addition
             when "001" =>
               y <= std_logic_vector(to_unsigned((to_integer(unsigned(b)) - to_integer(unsigned(a))),8)); --subtraction
             when "010" => -- multilication
               y <= std_logic_vector(to_unsigned((to_integer(unsigned(a)) * to_integer(unsigned(b))),8));
             when "011" => --division
               y <= std_logic_vector(to_unsigned((to_integer(unsigned(a)) / to_integer(unsigned(b))),8));
             when "100" =>
               if(a>b) then
                 y <= x"01";
               else 
                 y <= x"00";
               end if;      
             when "101" =>
               if (a<b) then
                 y <= x"01";
               else   
                 y <= x"00";
               end if;
             when "110" =>
               y(3 downto 0) <= a(3 downto 0) and b(3 downto 0);
               y(7 downto 4) <= "0000";
             when "111" =>
               y(3 downto 0) <= a(3 downto 0) or b(3 downto 0);
               y(7 downto 4) <= "0000";      
             when others =>
               y <= (others => '0');      
           end case;
         end if;
      end if; 
     end process;    
   --  y <= result;
end Behavioral;

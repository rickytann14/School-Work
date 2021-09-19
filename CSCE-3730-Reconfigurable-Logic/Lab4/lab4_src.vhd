----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 11/10/2020 12:38:00 PM
-- Design Name: 
-- Module Name: lab4_src - Behavioral
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
use IEEE.numeric_std.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity lab4_src is
   Port ( clk: in std_logic;   -- clock input
          reset: in std_logic; --reset input
          n: in std_logic_vector(1 downto 0);
          a: in std_logic_vector(1 downto 0);
          counter: out std_logic_vector(3 downto 0) -- 4bit counter
          );
end lab4_src;

architecture Behavioral of lab4_src is
signal count_up: std_logic_vector(3 downto 0);


begin
-- up counter
process(clk, reset)
variable exp : integer := 0;
begin
 if (reset = '0') then
 	count_up <= "0000";

 elsif(rising_edge(clk)) then
   if n = "10" and a = "01" then
   	  if count_up = "0000" then
   		  count_up <= "0010";
   	  elsif count_up = "0010" then
   		  count_up <= "0011";
   	  elsif count_up = "0011" then
   		  count_up <= "0101";
   	  elsif count_up = "0101" then
   		  count_up <= "1001";
   	  elsif count_up = "1001" then
   		  count_up <= "0000";
   	  else
   	      count_up <= "0000";
   	  end if;					
   elsif n = "11" and a = "01" then
  	  if count_up = "0000" then
   		  count_up <= "0010";
   	  elsif count_up = "0010" then
   		  count_up <= "0100";
   	  elsif count_up = "0100" then
   		  count_up <= "1010";
   	  elsif count_up = "1010" then
   		  count_up <= "0000";
	  else
   	      count_up <= "0000";
	  end if;
   elsif n = "11" and a = "10" then
   	  if count_up = "0000" then
   		  count_up <= "0011";
   	  elsif count_up = "0011" then
   		  count_up <= "0101";
   	  elsif count_up = "0101" then
   		  count_up <= "1011";
   	  elsif count_up = "1011" then
   		  count_up <= "0000";
   	  else
   	      count_up <= "0000";
   	  end if;
   end if;
 end if; 	
end process;
  counter <= count_up;    
end Behavioral;

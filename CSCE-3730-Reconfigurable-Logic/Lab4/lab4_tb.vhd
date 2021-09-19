----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 11/10/2020 05:25:25 PM
-- Design Name: 
-- Module Name: lab4_tb - Behavioral
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

entity lab4_tb is
--  Port ( );
end lab4_tb;

architecture Behavioral of lab4_tb is

component lab4_src 
  PORT(   clk: in std_logic;   -- clock input
          reset: in std_logic; --reset input
          n: in std_logic_vector(1 downto 0);
          a: in std_logic_vector(1 downto 0);
          counter: out std_logic_vector(3 downto 0) -- 4bit counter
          );
end component;
signal reset, clk: std_logic;
signal n, a: std_logic_vector(1 downto 0);
signal counter: std_logic_vector(3 downto 0);

begin

uut: lab4_src PORT MAP (
	clk => clk,
	n => n,
	a => a,
	reset => reset,
	counter => counter
);
process
begin
  reset <= '0';
  wait for 50ms;
  reset <= '1';
  n <= "10";
  a <= "01";
  clk <= '0';
  wait for 50ms;
  clk <= '1';
  wait for 50ms;
  clk <= '0';
  wait for 50ms;
  clk <= '1';
  wait for 50ms;
  clk <= '0';
  wait for 50ms;
  clk <= '1';
  wait for 50ms;
  clk <= '0';
  wait for 50ms;
  clk <= '1';
  wait for 50ms;
  clk <= '0';
  wait for 50ms;
  clk <= '1';
  wait for 50ms;
  clk <= '0';
  wait for 50ms;
  n <= "11";
  a <= "01";
  clk <= '0';
  wait for 50ms;
  clk <= '1';
  wait for 50ms;
  clk <= '0';
  wait for 50ms;
  clk <= '1';
  wait for 50ms;
  clk <= '0';
  wait for 50ms;
  clk <= '1';
  wait for 50ms;
  clk <= '0';
  wait for 50ms;
  clk <= '1';
  wait for 50ms;
  clk <= '0';
  wait for 50ms;
  clk <= '1';
  wait for 50ms;
  clk <= '0';
  wait for 50ms;
  n <= "11";
  a <= "10";
  clk <= '0';
  wait for 50ms;
  clk <= '1';
  wait for 50ms;
  clk <= '0';
  wait for 50ms;
  clk <= '1';
  wait for 50ms;
  clk <= '0';
  wait for 50ms;
  clk <= '1';
  wait for 50ms;
  clk <= '0';
  wait for 50ms;
  clk <= '1';
  wait for 50ms;
  clk <= '0';
  wait for 50ms;
  clk <= '1';
  wait for 50ms;
  clk <= '0';
  wait for 50ms;
  
  

  n <= "10";
  a <= "01";
  clk <= '0';
  wait for 50ms;
  clk <= '1';
  wait for 50ms;
  clk <= '0';
  reset <= '0';
  wait for 50ms;
  clk <= '1';
  wait for 50ms;
  clk <= '0';
  wait for 50ms;

  end process;
  

end Behavioral;

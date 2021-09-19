----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 11/21/2020 01:45:56 PM
-- Design Name: 
-- Module Name: vga_2crtl - Behavioral
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
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity vga_2crtl is
  Port ( 
  	clk_24: in std_logic_vector(1 downto 0);
  	vga_hs, vga_vs: out std_logic;
  	vga_red, vga_green, vga_blue: out std_logic_vector(3 downto 0)
  );
end vga_2crtl;

architecture Behavioral of vga_2crtl is

component vga_sync is
	Port(
		clk: in std_logic;
		hsync, vsync: out std_logic;
		red, green, blue: out std_logic_vector (3 downto 0)
	);
end component vga_sync;	

begin


end Behavioral;

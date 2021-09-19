----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 10/06/2020 07:33:32 PM
-- Design Name: 
-- Module Name: decode4to16 - Structure
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

entity decode4to16 is
    Port (  x : in STD_LOGIC_VECTOR (3 downto 0);
            en : in STD_LOGIC;
            y : out STD_LOGIC_VECTOR (15 downto 0));
end decode4to16;

architecture Structure of decode4to16 is
  Component decode2to4
   Port (  x : in STD_LOGIC_VECTOR (1 downto 0);
           en : in STD_LOGIC;
           y : out STD_LOGIC_VECTOR (3 downto 0));
  END Component;
  signal k: STD_LOGIC_VECTOR (3 downto 0);
BEGIN
  decoder0: decode2to4 port map(x(3 downto 2), en, k(3 downto 0));
  decoder1: decode2to4 port map(x(1 downto 0), k(0), y(3 downto 0));
  decoder2: decode2to4 port map(x(1 downto 0), k(1), y(7 downto 4));
  decoder3: decode2to4 port map(x(1 downto 0), k(2), y(11 downto 8));
  decoder4: decode2to4 port map(x(1 downto 0), k(3), y(15 downto 12));

END Structure;

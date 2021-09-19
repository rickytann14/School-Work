----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 10/06/2020 07:33:32 PM
-- Design Name: 
-- Module Name: decode2to4 - Behavioral
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

entity decode2to4 is
    Port (  x : in STD_LOGIC_VECTOR (1 downto 0);
           en : in STD_LOGIC;
           y : out STD_LOGIC_VECTOR (3 downto 0));
end decode2to4;

architecture Behavioral of decode2to4 is
signal enx: STD_LOGIC_VECTOR (2 downto 0);

begin
 enx <= en&x;
 WITH enx SELECT
   y <= "0001" WHEN "100",
        "0010" WHEN "101",
        "0100" WHEN "110",
        "1000" WHEN "111",
        "0000" WHEN OTHERS;
 
end Behavioral;

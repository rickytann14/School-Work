----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 09/22/2020 05:11:46 PM
-- Design Name: 
-- Module Name: lab1 - Behavioral
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

entity lab1 is
    Port (
     A, B, C, D: IN BIT;
     F: OUT BIT
    );
end lab1;
ARCHITECTURE lab1_architecture of lab1 IS
begin
  F <= (NOT B and C) OR (B and D) OR (A AND NOT B AND NOT D) OR (NOT A AND B AND NOT C);
END lab1_architecture;

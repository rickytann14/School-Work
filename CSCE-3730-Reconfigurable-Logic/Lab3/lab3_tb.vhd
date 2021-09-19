----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 10/19/2020 04:46:49 PM
-- Design Name: 
-- Module Name: lab3_tb - Behavioral
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

entity lab3_tb is
--  Port ( );
end lab3_tb;

architecture Behavioral of lab3_tb is
   COMPONENT lab_3source
   PORT( clock: in std_logic;
         --res: in std_logic;
         a: in std_logic_vector (3 downto 0);
         b: in std_logic_vector (3 downto 0);
         alu_select: in std_logic_vector (2 downto 0);
         y: out std_logic_vector(7 downto 0));
   END COMPONENT;
   
   --inputs?
   signal clock: std_logic := '0';
   signal res: std_logic := '0';
   signal a: std_logic_vector (3 downto 0) := (others => '0');
   signal b: std_logic_vector (3 downto 0) := (others => '0');
   signal alu_select: std_logic_vector (2 downto 0) := (others => '0');
   
   --outputs?
   signal y: std_logic_vector(7 downto 0);
   
--   constant CLK_PERIOD : time := 100ms;
   
 -- signal i:integer; 

begin
    uut: lab_3source PORT MAP(
      clock => clock,
--      res => res,
      a => a,
      b => b,
      alu_select => alu_select,
      y => y
    );
    
--    Clk_process :process
--    begin
--      clock <= '0';
--      wait for CLK_PERIOD/2; -- half of clock period stays at 0
--      clock <= '1';
--      wait for CLK_PERIOD/2; --half of clock period stays at 1
--    end process;
    
    --applying inputs here
  process
    begin

    --addition 
   -- y <= "00000000";   
    clock <= '0'; -- turn clock on
    wait for 50ms;
    alu_select <= "000";
    a <= "0001"; 
    b <= "0010";
    clock <= '1'; -- turn clock off
    wait for 50ms;
    
    clock <= '0'; -- turn clock on
    wait for 50ms;
    alu_select <= "000";
    a <= "0010"; 
    b <= "0011";
    clock <= '1'; -- turn clock off
    wait for 50ms;

    --subtraction
    clock <= '0'; -- turn clock on
    wait for 50ms;
    alu_select <= "001";
    a <= "0011"; 
    b <= "0100";
    clock <= '1'; -- turn clock off
    wait for 50ms;
    
    clock <= '0'; -- turn clock on
    wait for 50ms;
    alu_select <= "001";
    a <= "0100"; 
    b <= "0101";
    clock <= '1'; -- turn clock off
    wait for 50ms;
    
    --mulitplication
    clock <= '0'; -- turn clock on
    wait for 50ms;
    alu_select <= "010";
    a <= "0101"; 
    b <= "0110";
    clock <= '1'; -- turn clock off
    wait for 50ms;
    
    clock <= '0'; -- turn clock on
    wait for 50ms;
    alu_select <= "010";
    a <= "0110"; 
    b <= "0111";
    clock <= '1'; -- turn clock off
    wait for 50ms;
    
    --Division
    clock <= '0'; -- turn clock on
    wait for 50ms;
    alu_select <= "011";
    a <= "1100"; 
    b <= "0110";
    clock <= '1'; -- turn clock off
    wait for 50ms;
    
    clock <= '0'; -- turn clock on
    wait for 50ms;
    alu_select <= "011";
    a <= "1001"; 
    b <= "0011";
    clock <= '1'; -- turn clock off
    wait for 50ms;
    
        --Greater Than
    clock <= '0'; -- turn clock on
    wait for 50ms;
    alu_select <= "100";
    a <= "1111"; 
    b <= "0110";
    clock <= '1'; -- turn clock off
    wait for 50ms;
    
    clock <= '0'; -- turn clock on
    wait for 50ms;
    alu_select <= "100";
    a <= "0011"; 
    b <= "1101";
    clock <= '1'; -- turn clock off
    wait for 50ms;
    
        --Less than
    clock <= '0'; -- turn clock on
    wait for 50ms;
    alu_select <= "101";
    a <= "0100"; 
    b <= "1110";
    clock <= '1'; -- turn clock off
    wait for 50ms;
    
    clock <= '0'; -- turn clock on
    wait for 50ms;
    alu_select <= "101";
    a <= "1011"; 
    b <= "0001";
    clock <= '1'; -- turn clock off
    wait for 50ms;
    
        --AND Gate
    clock <= '0'; -- turn clock on
    wait for 50ms;
    alu_select <= "110";
    a <= "1110"; 
    b <= "1110";
    clock <= '1'; -- turn clock off
    wait for 50ms;
    
    clock <= '0'; -- turn clock on
    wait for 50ms;
    alu_select <= "110";
    a <= "1001"; 
    b <= "0011";
    clock <= '1'; -- turn clock off
    wait for 50ms;
    
        --OR Gate
    clock <= '0'; -- turn clock on
    wait for 50ms;
    alu_select <= "111";
    a <= "1100"; 
    b <= "0110";
    clock <= '1'; -- turn clock off
    wait for 50ms;
    
    clock <= '0'; -- turn clock on
    wait for 50ms;
    alu_select <= "111";
    a <= "1001"; 
    b <= "0011";
    clock <= '1'; -- turn clock off
    wait for 50ms;
    
    
   -- alu_select <= "000";
    --wait for 100ms;
   -- alu_select <= "001";
   -- wait for 100ms;
   -- alu_select <= "010";
   -- wait for 100ms;
   -- alu_select <= "011";
   -- wait for 100ms;
   --alu_select <= "100";
   -- wait for 100ms;
   -- alu_select <= "101";
   -- wait for 100ms;
   -- alu_select <= "110";
   -- wait for 100ms;
   -- alu_select <= "111";
   -- wait for 100ms;
    end process;
    
end Behavioral;